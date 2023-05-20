class Solution {
public:
    // DFS function for storing all the same connected nodes and saving the values in the visited 
    void DFS(unordered_map< string , unordered_map<string, double>>& adj , unordered_map<string, pair<double,int>>& visited ,int type , string s  )
    {

        for(auto it : adj[s])
        {
            if(visited.count(it.first)==0)
            {
                visited[it.first] = {(double)visited[s].first/it.second ,type} ;
                DFS(adj , visited , type , it.first);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map< string, pair<double,int>> store ;// pair will show the type whether it can resonates or not 
        unordered_map< string , unordered_map<string, double>> adj  ;
        // I have stored the values so taht at dfs we can directly take 
        for( int i =0 ;i<equations.size() ;i++)
        {
            adj[equations[i][0]][equations[i][1]] = values[i];
            double inverse = (double)1/values[i] ;
            adj[equations[i][1]][equations[i][0]] = inverse ;
        } 
        // Count varibale for distincting between different components 
        int count =0;
        for(auto it :adj)
        {
            if(store.count(it.first)==0)
            {
            // Giving the first value as 1 as they are ratios 
                store[it.first] = {1.0 , count};
                DFS(adj , store ,count , it.first );
                count ++;
            }
        }

        // At this point our store(visited ) is having all the necessary calculations which are valid 
        vector<double> ans  ;
        for( int i =0 ;i<queries.size() ;i++)
        {
            if(store.count(queries[i][0])==0 || store.count(queries[i][1])==0)
            {
                ans.push_back(-1);
                continue ;
            }
        // Checking the type of both string from queries 
            int type_1 = store[queries[i][0]].second ;
            int type_2 = store[queries[i][1]].second ;
            if(type_1!=type_2)
            {
                ans.push_back(-1);
                continue ;
            }
        // If type are same 
            double val = (double)(store[queries[i][0]].first)/store[queries[i][1]].first;
            ans.push_back(val);
        }
        return ans ;
    }
};
