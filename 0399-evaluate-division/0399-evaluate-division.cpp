class Solution {
public:
    vector<double> ans;
    unordered_map<string, vector<pair<string, double>>> adj;
    
    bool dfs(string& source, string& destin, unordered_set<string>& st, double& ans, double temp) {
        st.insert(source);
        
        if (adj.find(source) == adj.end() || adj.find(destin) == adj.end())
            return false;
        
        if (source == destin) {
            ans = temp;
            return true;
        }
        
        for (auto& it : adj[source]) {
            string i = it.first;
            double val = it.second;
            
            if (st.find(i) == st.end()) {
                if (dfs(i, destin, st, ans, temp * val)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int i = 0;
        for (auto& it : equations) {
            double val = values[i++];
            string a = it[0];
            string b = it[1];
            
            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }
        
        for (auto& it : queries) {
            double anss = 0;
            unordered_set<string> st;
            
            if (dfs(it[0], it[1], st, anss, 1.0) == false)
                anss = -1;
            
            ans.push_back(anss);
        }
        
        return ans;
    }
};
