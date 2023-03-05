class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> ump;
        
        for(auto &s : paths){
            // 1st one for root/a 1.txt
            int n = s.size(), i = 0;
            string path;
            while(i<n && s[i] != ' '){
                path += s[i++];
            }
            
            path += '/';            
            while(i<n){
                i++;
                string file,data;
                
                while(i<n && s[i] != '(')
                    file+=s[i++];
                
                i++;
                
                while(i<n && s[i] !=')')
                    data+=s[i++];
                
                i++;
                ump[data].push_back(path+file);
            }
            
        }
        
        for(auto it : ump){
            if(it.second.size()>1)
                ans.push_back(it.second);
        }
        
        return ans;
    }
};