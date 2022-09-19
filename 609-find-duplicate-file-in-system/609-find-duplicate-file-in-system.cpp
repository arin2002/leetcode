class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> ump;
        
        int n = paths.size();
        
        for(int i = 0; i<n; i++){
            string s = paths[i];
            int k = s.length();
            
            string path = "";
            int j = 0;
            
            while(j<k && s[j] != ' ')
                path += s[j++];
            
            path += '/';
            j++;
            
            while(j < k){
                string file = "", data = "";
                
                while(j < k && s[j] != '(')
                    file +=s[j++];
                
                while(j < k && s[j] != ' '){
                    data += s[j++];
                }
                
                ump[data].push_back(path+file);
                
                j++;
            }
        }
            
            for(auto i : ump){
                if(i.second.size() > 1)
                    ans.push_back(i.second);
            }
            
            return ans;
    }
};