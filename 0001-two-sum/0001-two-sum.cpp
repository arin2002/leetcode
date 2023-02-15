class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        vector<pair<int,int>> vp;
        
        int i = 0, j = nums.size()-1;
        for(auto it : nums){
            vp.push_back({it,i++});
        }
        
        sort(vp.begin(),vp.end());
        
        i = 0;
        while(i<j){
            int val = vp[i].first + vp[j].first;
            
            if(val == target){
                return {vp[i].second,vp[j].second};
            }
            
            else if(val < target)
                i++;
            
            else
                j--;
        }
        
        
        return ans;
    }
};