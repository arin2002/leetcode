class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int ans = 0;
        
        for(auto i:nums){
            s.insert(i);
        }
        
        for(int i = 0; i<n; i++){
            if(s.find(nums[i]-1) != s.end())
                continue;
            
            int curr = nums[i];
            int temp = 1;
            while(s.find(curr+1) != s.end()){
                curr +=1;
                temp++;
            }
            
            ans = max(ans,temp);
        }
        return ans;
    }
};