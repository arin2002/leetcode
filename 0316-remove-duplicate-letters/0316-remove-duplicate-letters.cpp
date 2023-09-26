class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int> count(26, 0);
       vector<int>  vis( 26, 0);
       string res = "";
       int n = s.size();
       for(int i = 0 ; i < n ; i++){
           count[ s[i] - 'a']++;
       } 

       for(int i = 0 ; i < n ; i++){
           count[ s[i] - 'a']--;

           if ( !vis[s[i] - 'a']){
               //last letter > s[i]
               //ans its count > 0
               while ( res.size() > 0 && res.back() > s[i] && count[res.back() - 'a'] > 0){
                    vis[ res.back()- 'a'] = 0;
                    res.pop_back();
               }
               res += s[i];
               vis [s[i] -'a'] = 1;
           }
       }
       return res;
    }
};
