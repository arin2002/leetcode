class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> freq(26);
        int n = s.size();
        
        int maxi = 0, count = 0, ans = 0;
        for(int i = 0; i<k; i++){
            freq[s[i]-'a']++;
            
            if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u')
                count++;
            
            ans = max(ans,count);
        }
        
        int i = 0;
        for(int j = k; j<n; j++){
            if(s[j] == 'a'||s[j] == 'e'||s[j] == 'i'||s[j] == 'o'||s[j] == 'u')
                count++;
            
            if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u')
                count--;
            
            i++;
            ans = max(ans,count);
        }
        
        return ans;
    }
};