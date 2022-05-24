class Solution {
public:
    
    bool palind(string s,int l , int h)
    {
        while(l<h)
        {
            if(s[l] != s[h])
                return false;
            l++; h--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        int l = 0,h = n-1;
        bool flag = true;;
        
        while(l<h)
        {
            if(s[l]==s[h]){
                l++; h--;
            }
            else return palind(s,l+1,h) || palind(s,l,h-1);
        }
        
        return true;
    }
};