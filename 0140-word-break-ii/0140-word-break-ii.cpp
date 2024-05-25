class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans, t;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = s.size();
        
        function<void(int)> solve = [&](int ind){
            if(ind == n){
                string temp;
                for(auto &it: t){
                    temp += it+" ";
                }
                temp.pop_back();
                ans.push_back(temp);
                return;
            }
            
            string temp;
            for(int i = ind; i<n; i++){
                temp += s[i];
                auto it = st.find(temp);
                
                t.push_back(temp);
                if(it != st.end()){
                    solve(i+1);
                }
                t.pop_back();
            }
        };
        
        solve(0);
        return ans;
    }
};