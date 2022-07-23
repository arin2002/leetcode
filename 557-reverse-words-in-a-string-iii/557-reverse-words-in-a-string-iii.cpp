class Solution {
public:
    
    void reverse(int i, int j, string &s)
    {
        while(i<j)
        {
            swap(s[i],s[j]);
            i++; j--;
        }
    }
    
    string reverseWords(string s) {
        int n = s.length();
        
        int i = 0, j = 0;
        
        while(j<n)
        {
            if(s[j]==32)
            {
                reverse(i,j-1,s);
                i = j+1;
            }
            else if(j==n-1)
                reverse(i,j,s);
            j++;
        }
        
        return s;
    }
};