class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> degree; // in & out degree records
        unordered_map<int, vector<int> > adj;
        
        for (const auto& pair : pairs) {
            int u = pair[0];
            int v = pair[1];

            degree[u]++; // increment degree while edge going out
            degree[v]--; // decrement degree while edge coming in

            adj[u].push_back(v);
        }

        // since the euler path exists, there must be either 0, or 2 nodes
        // whose degree is odd
        int start = pairs[0][0]; // default node when there is no node with odd degree
        for(const auto& item: degree){
            if(item.second == 1){
                start = item.first;
                break;
            }
        }

        // construct the Euler path
        vector<int> eulerPath;
        stack<int> st;
        st.push(start);

        while(!st.empty()){
            int currNode = st.top();
            auto& nbrs = adj[currNode]; // get the neighbours of current node

            if(nbrs.empty()){
                // push the currNode down the path if all it's edges are used
                eulerPath.push_back(currNode);
                st.pop();
            }else{
                // remove the edge b/w currNode and a nbr and push the nbr into stack
                int nbr = nbrs.back();
                st.push(nbr);
                nbrs.pop_back();
            }
        }

        // now the eulerPath contains the path in reversed sequence
        vector<vector<int>> ans;
        reverse(eulerPath.begin(), eulerPath.end());
        for(int i=0; i<eulerPath.size()-1; i++){
            int u = eulerPath[i];
            int v = eulerPath[i+1];
            ans.push_back({u, v});
        }
        
        return ans;
    }
};
