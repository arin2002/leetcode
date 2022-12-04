class Solution {
public:
    bool isCircularSentence(string s) {
        unordered_map<char,int> ump;
        
        
        if(s[0] !=  s[s.size()-1])
            return false;
        
        for(int i = 0; i<s.length()-1; i++){
            if(s[i] != ' ' && s[i+1] == ' ' && s[i+2] != s[i])
                return false;
        }
        
        return true;
    }
};