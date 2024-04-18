class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> suffix(n);
        suffix[n-1] = (s[n-1] == '1' ? 1: 0);
        int ans = 0;
        
        for(int i = n-2; i>=0; i--){
            suffix[i] = suffix[i+1];
            
            if(s[i] == '1'){
                suffix[i]++;
            }
        }
        
        int curr = (s[0] == '0' ? 1: 0);
        for(int i = 1; i<n; i++){
            ans = max(ans,curr+suffix[i]);
            
            if(s[i] == '0')
                curr++;
        }
        
        return ans;
    }
};