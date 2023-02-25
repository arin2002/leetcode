class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq, p;
        
        for(int i = 0; i<nums.size(); i++){
            pq.push({nums[i],i});
            
            if(pq.size()>k)
                pq.pop();
        }        

        while(!pq.empty()){
            p.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        
        return ans;
    }
};