class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void permu(vector<int> nums,int n,vector<int> &check)
    {
        if(temp.size() == n){
            // temp.push_back(nums);
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i<n; i++)
        {
            if(check[i] == 0){
                temp.push_back(nums[i]);
                check[i] = 1;
                permu(nums,n,check);
                temp.pop_back();
                check[i] = 0;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n,0);
        
        // for(int i = 0; i<n; i++)
            permu(nums,n,check);
        
        return ans;
    }
};