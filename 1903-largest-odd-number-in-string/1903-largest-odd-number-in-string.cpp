class Solution {
public:
    string largestOddNumber(string s) {
        string ans = "";
        
        int i = 0, j = s.size()-1;
        
        while(j>=0){
            int n = s[j]-48;
//             string a = "";
//             a += s[j];
//             int n = stoi(a);
            
            if(n%2){
                // cout<<s[j];
                // cout<<n;
                break;
            }
            else
                s.pop_back();
            
            j--;
        }
        
        return s;
    }
};