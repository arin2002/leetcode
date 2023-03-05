class Solution {
public:
    vector<int> vis;
    
    bool solve(int ind,vector<int>& arr){
        if(ind >= arr.size())
            return false;
        
        if(arr[ind] == 0)
            return true;
        
        bool l = false, r = false;
        if(!vis[ind]){
            vis[ind] = 1;
            l = solve(ind+arr[ind],arr);
            vis[ind] = 0;
        }
        
        // vis[ind] = 0;
        
        if(!vis[ind]){
            vis[ind] = 1;
            r = solve(ind-arr[ind],arr);
            vis[ind] = 0;
        }
        
        return l|r;
    }
    
    bool canReach(vector<int>& arr, int start) {
        vis.resize(arr.size());
        return solve(start,arr);
    }
};