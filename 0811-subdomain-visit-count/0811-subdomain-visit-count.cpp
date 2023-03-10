class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string,int> ump;
        
        for(auto &s: cpdomains){
            string num;
            
            int i = 0;
            while(s[i] != ' '){
                num += s[i++];
            }
            
            // for space
            i++;            
            string st = s.substr(i);
            
            for(i = 0; i<st.size(); i++){
                if(st[i] == '.')
                    ump[st.substr(i+1)]+=stoi(num);
            }
            
            ump[st]+=stoi(num);
        }
        
        for(auto it : ump){
            string temp = to_string(it.second)+ " " +(it.first);
            ans.push_back(temp);
        }
        
        return ans;
    }
};