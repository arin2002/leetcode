class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        
        sort(folder.begin(),folder.end(),[&](auto a, auto b){
           return a.size()<b.size(); 
        });
        
        unordered_map<string,int> ump;
        for(auto &s : folder){
            
            int flag = 0; string temp;
            for(int i = 0; i<s.size(); i++){
                temp+=s[i];
                if(ump.find(temp) != ump.end() && i<s.size() && (s[i]>='a' && s[i] <= 'z') && !(s[i+1]>='a' && s[i+1] <= 'z')){
                    flag = 1;
                    break;
                }
            }
            
            
            if(flag)
                continue;
            
            ump[s] = 1;
            ans.push_back(s);
        }
        return ans;
    }
};