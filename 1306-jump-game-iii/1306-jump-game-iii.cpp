class Solution {
public:
    
//     bool solve(int ind,vector<int>& arr,vector<int> vis){
//         if(ind >= arr.size())
//             return false;
        
//         if(arr[ind] == 0)
//             return true;
        
//         bool l = false, r = false;
//         if(!vis[ind]){
//             vis[ind] = 1;
//             l = solve(ind+arr[ind],arr,vis);
//             vis[ind] = 0;
//         }
        
//         // vis[ind] = 0;
        
//         if(!vis[ind]){
//             vis[ind] = 1;
//             r = solve(ind-arr[ind],arr,vis);
//             vis[ind] = 0;
//         }
        
//         return l|r;
//     }
    
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size());
        // return solve(start,arr,vis);
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            
            int left = ind - arr[ind], right = arr[ind]+ind;
            if(left >= 0){
                if(arr[left] == 0)
                    return true;
                
                else if(!vis[left])
                    q.push(left); 
            }
            
            if(right<arr.size()){
                if(arr[right] == 0)
                    return true;
                
                else if(!vis[right])
                    q.push(right);
            }
            
            // mark it visited
            vis[ind] = 1;
        }
        
        return false;
    }
};