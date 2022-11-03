class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> v(26,vector<int>(26,0));;
        int ans = 0;
        
        for(auto it : words){
            int a = it[0]-'a';
            int b = it[1]-'a';

            if(v[b][a]){
                ans+=4;
                v[b][a]--;
            }
            else
                v[a][b]++;
        }
        
        for(int i = 0; i<26; i++){
            if(v[i][i]){
                ans+=2;
                break;
            }
        }
        
        return ans;
    }
};
