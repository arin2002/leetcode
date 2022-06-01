class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        int i = 0, j = 0;
        string ans = "";
        while(i<n && j < m){
            ans += word1[i];
            ans +=word2[j];
            i++; j++;
        }
        
        for(;i<n;i++)
            ans += word1[i];
        
        for(;j<m;j++)
            ans += word2[j];
        
        return ans;
    }
};