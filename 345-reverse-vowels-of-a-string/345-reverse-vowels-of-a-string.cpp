class Solution {
public:
    bool checkForVowel(char chr){
        if(chr=='a' || chr=='e' || chr=='i' || chr=='o' || chr=='u' || chr=='A' || chr=='E' || chr=='I' || chr=='O' || chr=='U' )
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0,j=n-1;
        while(i<j){
            if(checkForVowel(s[i]) && checkForVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(checkForVowel(s[i]))
                j--;
            else if(checkForVowel(s[j]))
                i++;
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};
