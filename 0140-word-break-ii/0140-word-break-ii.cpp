class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = s.size();
        
        function<void(int,string)> solve = [&](int ind, string t){
            if(ind == n){
                t.pop_back();
                ans.push_back(t);
                return;
            }
            
            string temp;
            for(int i = ind; i<n; i++){
                temp += s[i];
                auto it = st.find(temp);
                
                if(it != st.end()){
                    solve(i+1,t+temp+" ");
                }
            }
        };
        
        solve(0,"");
        return ans;
    }
};