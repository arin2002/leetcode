class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = false;
        
        // lowecase 
        if(word[0] >=97){
            for(int  i = 0; i<word.size(); i++){
                if(word[i]<96)
                    return false;
            }
            
            return true;
        }
        
        // lower
        if(word[1] >= 97)
            flag = true;
        
        if(flag){
            for(int i = 1; i<word.size(); i++){
                if(word[i] < 97)
                    return false;
            }
        }
        else{
            for(int i = 1; i<word.size();i++){
                // cout<<(int)word[i];
                if(word[i] >= 97)
                    return false;
            }
        }
        return true;
    }
};