class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> ump;
        
        for(auto &it: nums){
            ump[it]++;
        }
        
        for(auto &[a,b]: ump){
            if(pq.size()>=k){
                int freq = pq.top().first;
                if(b>freq){
                    pq.pop();
                    pq.push({b,a});
                }
            }
            else
                pq.push({b,a});
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};