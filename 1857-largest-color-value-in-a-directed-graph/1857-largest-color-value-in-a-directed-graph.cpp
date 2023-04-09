class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), ans = 0;
        vector<int> inDegree(n), adj[n];
        
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }
        
        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;
        
        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        int nodeSeen = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodeSeen++;
            
            ans = max(ans, ++count[node][colors[node]-'a']);
            
            for(auto &it: adj[node]){
                for(int i = 0; i<26; i++){
                    count[it][i] = max(count[it][i], count[node][i]);
                }
                
                inDegree[it]--;
                
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        return nodeSeen < n ? -1 : ans;
    }
};