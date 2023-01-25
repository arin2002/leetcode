class Solution {
public:
    
    
    void bfs(int node, vector<int>& edges,vector<int> &vis, vector<int> &dis){
        queue<int> q;
        q.push(node);
        
        int c = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = 1;
            
            int next = edges[node];
            
            if(next != -1 && !vis[next]){
                q.push(next);
                dis[next] = c;
            }
            
            c++;
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        // if(node1 == node2)
        //     return 0;
        
        int n = edges.size();
        
        vector<int> vis1(n,0), vis2(n,0), dist1(n,-1), dist2(n,-1);
        dist1[node1] = 0; dist2[node2] = 0;
        bfs(node1,edges,vis1,dist1);
        bfs(node2,edges,vis2,dist2);
                
        int ans = INT_MAX, ind = 0;
        
        // for(int i = 0; i<n; i++){
        //     cout<<dist1[i]<<" "<<dist2[i]<<endl;
        // }
        
        for(int i = 0; i<n; i++){
            if(dist1[i] == -1 || dist2[i] == -1)
                continue;
            
            int dist = max(dist1[i],dist2[i]);
            
            if(ans>dist){
                ans = dist;
                ind = i;
            }
        }
        
        if(ans == INT_MAX)
            return -1;
        
        return ind;
    }
};