class Graph {
public:
    vector<pair<int,int>> adj[101];
    int n;
    
    Graph(int n, vector<vector<int>>& edges) {
        this-> n = n;
        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(n,INT_MAX);
        pq.push({node1,0});
        ans[node1] = 0;
        
        while(!pq.empty()){
            int currN = pq.top().first;
            int currD = pq.top().second;
            
            pq.pop();
            
            for(auto &node: adj[currN]){
                int negibN = node.first;
                int negibD = node.second;
                
                if(currD+negibD <= ans[negibN]){
                    ans[negibN] = currD+negibD;
                    pq.push({negibN,currD+negibD});
                }
            }
        }
        
        return ans[node2] == INT_MAX ? -1: ans[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */