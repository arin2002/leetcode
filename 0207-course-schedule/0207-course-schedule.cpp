class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<int> inDegree(n);
        vector<int> adj[n];
    
        for(auto &it: nums){
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it: adj[node]){
                inDegree[it]--;
                
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        for(int i = 0; i<n; i++){
            if(inDegree[i])
                return false;
        }
        
        return true;
    }
};