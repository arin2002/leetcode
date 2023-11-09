#define ll long long
class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        ll ans = n;
        
        string t;
        ll mod = 1e9+7;
        for(int i = 0; i<n; i++){
            
            if(t.size()>0 && t[0] != s[i]){
                ll m = t.size();
                ans = (ans%mod + m*(m-1)/2)%mod;
            }
            
            while(t.size()>0 && s[i] != t[0]){
                    t.pop_back();
            }
            
            t += s[i];
        }
        
        if(t.size()>0){
            ll m = t.size();
            ans = (ans%mod + m*(m-1)/2)%mod;
        }
        
        return ans%mod;
    }
};