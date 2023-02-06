class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> x1, y1, ans;
        
        int i = 0, y = n, z = 0;
        while(i<n || y<2*n){
            if(z%2 == 0)
                ans.push_back(nums[i++]);
            else{
                ans.push_back(nums[y++]);
            }
            
            z++;
        }
        
        return ans;
    }
};