class Solution {
public:
    
    // bool solve(int cur, vector<int> &nums, int ind){
    //     if (ind > 0 && nums[ind - 1] == nums[p] && nums[ind - 1] != 0) {
    //         cur += (inc ? 1 : -1);
    //     }
    //     if (ind < nums.size() - 1 && nums[ind + 1] == nums[ind] && nums[ind + 1] != 0) {
    //         cur += (inc ? 1 : -1);
    //     }
    //     return cur;
    // }
    
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n),ans,vis(n);
        
        int adjCount = 0;
        for(auto &it: queries){
            int ind = it[0];
            int col = it[1];
            
            // same color no need to do anything
            // if(nums[ind] == col)
            //     continue;
            
            // minus the contribution
            if(ind>0 && nums[ind] == nums[ind-1] && nums[ind]!=0){
                adjCount--;
            }
            
            if(ind<n-1 && nums[ind] == nums[ind+1] && nums[ind] != 0){
                adjCount--;
            }
            
            nums[ind] = col;
            
            if(ind>0 && nums[ind] == nums[ind-1]){
                adjCount++;
            }
            
            if(ind<n-1 && nums[ind] == nums[ind+1]){
                adjCount++;
            }
            ans.push_back(adjCount);
        }
        
        return ans;
    }
};