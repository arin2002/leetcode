class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        
        int ans = 0;
        if(tokens.size() == 0 || tokens[0] > power)
            return 0;
        
        int i = 0, j = n-1;
        
        while(i<=j){
            if(tokens[i] <= power){
                power -= tokens[i];
                i++;
                ans++;
            }
            else if(i == j){
                i++;
                continue;
            }
            else{
                power += tokens[j];
                j--;
                ans--;
            }
        }
        
        return ans;
    }
};