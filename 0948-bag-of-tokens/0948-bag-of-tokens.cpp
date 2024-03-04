class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int pow) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int l = 0, r = n-1, ans = 0;
        
        while(l<=r){
            if(tokens[l] <= pow){
                pow -= tokens[l++];
                ans++;
            }
            else{
                if(ans>0 && l!=r){
                    pow += tokens[r--];
                    ans--;
                }
                else{
                    break;
                }
            }
            
            cout<<pow<<" ";
        }
        
        return ans;
    }
};