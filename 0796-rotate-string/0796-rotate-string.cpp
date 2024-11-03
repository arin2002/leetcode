class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        // vector<int> adj[n];
        if(n != m)
            return 0;
        
        unordered_map<char,vector<char>> adj;
        
        for(int i = 0; i<n-1; i++){
            adj[s[i]].push_back(s[i+1]);
        }
        
        adj[s[n-1]].push_back(s[0]);
        
        
        function<int(int)> solve = [&](int ind){
            if(ind == n-1){
                return 1;
            }
            
            char curr = goal[ind];
            char next = goal[ind+1];
            
            cout<<curr<<" "<<next<<" ";
            
            for(auto &it: adj[curr]){
                if(it == next){
                    cout<<it<<endl;
                    if(solve(ind+1) == 1)
                        return 1;
                }
            }
            
            return 0;
        };
        
        return solve(0);
    }
};