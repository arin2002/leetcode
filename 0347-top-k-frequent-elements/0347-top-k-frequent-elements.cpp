class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int,int> ump;
        unordered_set<int> s;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it : nums){
            s.insert(it);
            ump[it]++;
        }
        
        for(auto it : s){
            pq.push({ump[it],it});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};