class Solution {
public:
    
    bool vowel(char &it){
        
        if(it == 'a'||it == 'e'||it == 'i'||it == 'o'||it == 'u')
            return 1;
        else if(it == 'A'||it == 'E'||it == 'I'||it == 'O'||it == 'U')
            return 1;
        
        return 0;
    }
    
    
    bool halvesAreAlike(string s) {
        
        int mid = s.size()/2;
        
        int count1 = 0, count2 = 0;
        for(int i = 0; i<s.size()/2; i++){
            if(vowel(s[i]))
                count1++;
            
            if(vowel(s[i+mid]))
                count2++;
                
        }
    
        return count1 == count2;
            
    }
};