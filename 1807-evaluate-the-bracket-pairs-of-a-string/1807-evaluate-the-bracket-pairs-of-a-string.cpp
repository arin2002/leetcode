class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> ump;
        
        for(auto &it : knowledge)
            ump[it[0]] = it[1];
        
        
        int i = 0, n = s.size();
        string ans;
        
        while(i<n){
            if(s[i] == '('){
                i++;
                string key;
                while(i<n && s[i] != ')'){
                    key += s[i++];
                }
                i++;
                
                auto it = ump.find(key);
                
                if(it == ump.end())
                    ans += '?';
                else
                    ans += it->second;
            }
            else{
                ans += s[i++];
            }
        }
        
        return ans;
    }
};