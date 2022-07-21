class Solution {
public:
    bool isSubsequence(string s, string t) {    
        int n = s.length();
        int m = t.length();
        int count = 0;
        
        
        if(n == 0 && m==0)
            return true;
        
        for(int i = 0; i<m; i++)
        {
            if(t[i] == s[count])
                count++;
            
            cout<<count;
            if(count == n)
                return true;
        }
        
        return false;
    }
};