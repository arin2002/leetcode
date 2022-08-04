class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        int m = nums.size();
        
        int i = 0, j = n;
        bool flag = true;
        while(i<=j && j<m){
            if(flag){
                flag = !flag;
                v.push_back(nums[i++]);
            }
            else{
                flag = !flag;
                v.push_back(nums[j++]);
            }
        }
        
        return v;
    }
};