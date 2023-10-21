class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res = nums[0], n = nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        
        for(int i = 1; i<n; i++){
            
            while(!pq.empty() && i-pq.top().second > k){
                pq.pop();
            }
            
            if(!pq.empty()){
                int t = nums[i]+pq.top().first;
                nums[i] = max(nums[i],t);
                res = max(res,nums[i]);
                pq.push({nums[i],i});
            }
        }
        
        return res;
    }
};