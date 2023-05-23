class Solution {
public:
    
    int check(int i,vector<vector<int>>& grid, map<vector<int>,int> &ump){
        vector<int> nums;
        for(int j = 0; j<grid.size(); j++){
            nums.push_back(grid[j][i]);
        }
        
        if(ump.find(nums) == ump.end())
            return 0;
        
//         for(auto it: nums)
//             cout<<it<<" ";
        
//         cout<<endl;
        return ump[nums];
    }
    
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        map<vector<int>,int> ump;
        
        for(auto &it: grid){
            ump[it]++;
        }
        
        for(int i = 0; i<n; i++){
            ans += check(i,grid,ump);
        }
        
        return ans;
    }
};