class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        
        int remove = 0;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == '*'){
                remove++;
            }
            else{
                if(remove > 0){
                    remove--;
                    continue;
                }
                
                ans+=s[i];
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
