class Solution {
public:
    string reverseWords(string s) {
        string ans = "";        
        int n = s.length();
        vector<string> v;
        
        
        for(int i = 0; i<n; i++){
            while(s[i] == ' ')  i++;
            
            string temp;
            while(i<n && s[i] != ' '){ 
                temp +=s[i++];
            }
            
            if(temp.size() != 0)
                v.push_back(temp);
        }
        
        reverse(v.begin(),v.end());
        
        for(int i = 0; i<v.size(); i++){
            if(i == v.size()-1)
                ans+= v[i];
            else
                ans = ans + v[i] + ' ';
        }
    
        return ans;
    }
};