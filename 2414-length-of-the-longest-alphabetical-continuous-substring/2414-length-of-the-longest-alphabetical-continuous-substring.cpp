class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int ans = 1, temp = 1;
        
        for(int i = 1; i<s.length(); i++){
            // int curr = s[i]-'a';
            // int prev = s[i-1] - 'a';
            
            if(s[i]-s[i-1] == 1){
                temp++;
            }
            else
                temp = 1;
            
            ans = max(ans,temp);
        }
        
        return ans;
    }
};