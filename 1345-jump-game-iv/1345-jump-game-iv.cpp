class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,vector<int>> ump;
        for(int i = 0; i<n; i++){
            ump[arr[i]].push_back(i);
        }
        
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        
        int count = 0;
        
        while(!q.empty()){
            int m  = q.size();
            
            while(m--){
                int ind = q.front();
                q.pop();
                
                if(ind == n-1)
                    return count;
            
                int l = ind+1;
                int r = ind-1;
            
                if(l<n && !vis[l]){
                    vis[l] = 1;
                    q.push(l);
                }
            
                if(r>=0 && !vis[r]){
                    vis[r] = 1;
                    q.push(r);
                }
            
                for(auto it : ump[arr[ind]]){
                    if(!vis[it] && it != ind){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
                
                ump[arr[ind]].clear();
            }
            
            count++;
        }
        
        return -1;
    }
};