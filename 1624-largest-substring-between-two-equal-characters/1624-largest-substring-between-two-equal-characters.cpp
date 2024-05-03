class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(),start = 0, ans = -1;
        vector<int> freq(26,-1);
        
        for(int end = 0; end<n; end++){
            
            if(freq[s[end]-'a'] == -1){
                freq[s[end]-'a'] = end;
            }
            else{
                ans = max(ans,end-freq[s[end]-'a']-1);
            }
        }
        
        return ans;
    }
};