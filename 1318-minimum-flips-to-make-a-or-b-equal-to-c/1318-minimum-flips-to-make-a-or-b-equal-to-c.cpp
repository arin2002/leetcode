class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a || b || c){
            int p = (a&1);
            int q = (b&1);
            int r = (c&1);
            
            int t = p|q;
            
            // cout<<p<<" "<<q<<" "<<r<<" "<<t<<endl;
            if(t != r){
                if(t == 0){
                    // if(a == 1 || b == 1)
                    ans++;
                }
                else{
                    ans +=2;
                    if(p == 0 || q == 0)
                        ans--;
                }
            }
            cout<<p<<" "<<q<<" "<<r<<" "<<t<<" "<<ans<<endl;
            a>>=1;
            b>>=1;
            c>>=1;
        }
        
        return ans;
    }
};