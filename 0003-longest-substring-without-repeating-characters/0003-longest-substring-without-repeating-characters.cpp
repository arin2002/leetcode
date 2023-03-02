class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0, i = 0;
        
        unordered_map<char,int> ump;
        int ans = 0, temp = 0;
        
        while(j<s.size() && i<s.size()){
            // cout<<i<<" "<<j<<endl;
            
//             if(s[j] == ' ')
//                 j++;
            
//             if(s[i] == ' ')
//                 i++;
            
            if(ump.find(s[j]) == ump.end() || ump[s[j]] == 0){
                temp++;
                ump[s[j]]++;
                j++;
            }
            else{
                ump[s[i]]--;
                i++;
                temp--;
            }
            ans = max(ans,temp);
        }
        
        return ans;
    }
};