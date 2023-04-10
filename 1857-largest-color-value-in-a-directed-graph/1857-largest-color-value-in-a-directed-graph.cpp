class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // bfs kar rahe h ek tare se ham
        // bas ye scene h ki value store kara rahe har node pe
        // uske color ki
        // aur ye bfs basically topo sort jaisa ha aur kuch nhi
        // dp jaisa h as we are storing values
        
        // no of nodes
        int n = colors.size(), total = 0, ans = 0;
        vector<int> adj[n], indegree(n);
        queue<int> q;
        // this is for carrying information of max from each node
        // there can be 26 colors so thats why
        vector<vector<int>> count(n,vector<int>(27));
        
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        // now push 0 wale kyuki vahi se to bfs hoga
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        // start bfs
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // update that color
            total++;
            count[node][colors[node]-'a']++;
            ans = max(ans,count[node][colors[node]-'a']);
            
            for(auto &edge: adj[node]){
                // before doing anything update the colors for that node
                // till the max we have seen as it can contribute later on
                for(int i = 0; i<27; i++){
                    count[edge][i] = max(count[edge][i],count[node][i]);
                }
                
                indegree[edge]--;
                if(indegree[edge] == 0)
                    q.push(edge);
            }
        }
        
        return total == n ? ans : -1;
    }
};