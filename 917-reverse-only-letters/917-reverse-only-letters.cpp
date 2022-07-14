class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n  = s.length();
        string letter = "";
        
        for(int i = 0; i<n; i++)
        {
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
                cout<<1;
                letter +=s[i];
            }
        }
        
        reverse(letter.begin(),letter.end());
        cout<<letter.length();
        int k = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
                cout<<1;
                s[i] = letter[k++];
            }
        }
        
        return s;
        
    }
};