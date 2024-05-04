class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ans  = -1, zeroL = 0, oneL = 0;
        // ans = zeroL + oneR
        // ans = zeroL + (total_1-oneL)
        // ans = (zeroL-oneL) + total_1
        // total_1 is constant hence we need to find
        // max value of (zeroL-oneL) which depends on left only
        
        for(int i = 0; i<n-1; i++){
            if(s[i] == '1'){
                oneL++;
            }
            else{
                zeroL++;
            }
            
            ans = max(ans,zeroL-oneL);
        }
        
        if (s[n - 1] == '1') {
            oneL++;
        }
        
        cout<<ans<<" "<<oneL;
        return ans + oneL;
    }
};