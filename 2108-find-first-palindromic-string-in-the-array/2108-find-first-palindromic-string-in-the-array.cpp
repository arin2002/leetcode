class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(auto &it: words){
            string t = it;
            reverse(t.begin(),t.end());
            
            if(it == t)
                return it;
        }
        
        return "";
    }
};