class Solution {
public:
    string reverseWords(string s) {
        string ans = "";        
        int n = s.length();
        vector<string> v;
        
//         for(int i = 0; i<n-1; i++){
//             if(s[i] != ' ' && s[i+1] == ' '){
//                 ans = ans + s[i] + ' ';
//             }
            
//             else if(s[i] != ' ')
//                 ans +=s[i];
//         }
        
//         //reverse(ans.begin(),ans.end());
//         if(s[n-1] != ' ' && s[n-2] != ' '){
//             ans+=s[n-1];
//         }
        
//         else if(s[n-1] != ' ' && s[n-2] == ' '){
//             ans = ans + ' ' + s[n-1];
//         }
        
        int i = 0;
        while(i<n){
            while(s[i] == ' ') i++;
            
            string temp;
            while(i<n && s[i] != ' '){ 
                temp +=s[i++];
            }
            
            if(temp.size() != 0)
                v.push_back(temp);
            
            i++;
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