class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        string t, ans;
        for(int i = 0; i<n; i++){
            
            if(s[i] == ' '){
                reverse(t.begin(),t.end());
                ans += t+" ";
                t = "";
            }
            else{
                t += s[i];
            }
        }
        
        reverse(t.begin(),t.end());
        ans += t;
        return ans;
    }
};