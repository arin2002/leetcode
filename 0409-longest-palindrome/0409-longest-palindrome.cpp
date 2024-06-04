class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        
        for(auto &it: s){
            freq[it]++;
        }
        
        int ans = 0, flag = 1;
        for(auto &[a,fre]: freq){
            
            if(fre%2 && flag){
                ans += fre;
                flag = 0;
                
            }
            else if(fre%2 == 1)
                ans += fre-1;
            
            else if(fre%2 == 0)
                ans += fre;
        }
        
        return ans;
    }
};