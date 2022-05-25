class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1, count =0;
        
        while(i>=0)
        {
            if(s[i]>='a' && s[i] <='z' || s[i]>='A' && s[i] <='Z' )
            {
                count ++ ;
                if(i-1<0)
                    break;
                if(!(s[i-1]>='a' && s[i-1]<='z' || s[i-1]>='A' && s[i-1]<='Z'))
                    break;
                i--;
            }
            else if(!(s[i]>='a' && s[i-1]<='z' || s[i]>='A' && s[i]<='Z'))
                i--;
        }
        
        return count;
    }
};