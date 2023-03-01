class Solution {
public:
    
    unordered_set<string> st;
    vector<int> vis;
    
    void solve(string &s, string temp){
        
        st.insert(temp);
        // cout<<temp<<endl;
        for(int i = 0; i<s.size(); i++){
            if(vis[i] == 1)
                continue;
            
            temp.push_back(s[i]);
            vis[i] = 1;
            // st.insert(temp);
            solve(s,temp);
            temp.pop_back();
            vis[i] = 0;
        }
    }
    
    int numTilePossibilities(string tiles) {
        vis.resize(28);
        solve(tiles,"");
        return st.size()-1;
    }
};