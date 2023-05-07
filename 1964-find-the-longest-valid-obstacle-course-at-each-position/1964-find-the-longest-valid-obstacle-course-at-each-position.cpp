class Solution {
public:    
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans,temp;
        
        ans.push_back(1);
        temp.push_back(nums[0]);
        
        for(int i = 1; i<n; i++){
            if(temp.back()<=nums[i]){
                temp.push_back(nums[i]);
                ans.push_back(temp.size());
            }
            else{
                int ind = upper_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
                ans.push_back(ind+1);
            }
        }
        
        return ans;
    }
}; 