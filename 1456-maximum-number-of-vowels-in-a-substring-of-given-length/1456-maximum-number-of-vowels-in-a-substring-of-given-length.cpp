class Solution {
public:
    
    bool isVowel(char s){
        return (s=='a' || s== 'e' || s== 'i' || s== 'o' || s== 'u');
    }
    
    
    int maxVowels(string s, int k) {
        int ans = 0, n = s.size();
        // unordered_map<char,int> ump;
        for(int i = 0; i<k; i++){
            if(isVowel(s[i])){
                // ump[s[i]]++;
                ans++;
            }
        }
        
        int temp = ans, start = 0;
        for(int i = k; i<n; i++){
            if(isVowel(s[start++])){
                // ump[s[i]]--;
                temp--;
            }
            
            if(isVowel(s[i])){
                temp++;
            }
            
            ans = max(ans,temp);
        }
        
        return ans;
    }
};