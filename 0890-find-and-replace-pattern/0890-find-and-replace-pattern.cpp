class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto &s : words){
            unordered_map<char,char> ump, ump1;
            if(s.size() != pattern.size())
                continue;
            
            int i = 0, j = 0;
            for(auto it : s){
                if(ump.find(pattern[i]) == ump.end() && ump1.find(it) == ump1.end()){
                    ump[pattern[i]] = it;
                    ump1[it] = pattern[i++];
                }
                else{
                    if(ump[pattern[i]] != it && ump1[it] != pattern[i]){
                        j = 1;
                        break;
                    }
                    i++;
                }
            }
            
            if(!j)
                ans.push_back(s);
        }
        
        return ans;
    }
};