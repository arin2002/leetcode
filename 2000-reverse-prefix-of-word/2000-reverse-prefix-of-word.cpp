class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size(), ind = -1;
        
        for(int i = 0; i<n; i++){
            if(word[i] == ch){
                ind = i;
                break;
            }
        }
        
        int i = 0;
        while(i < ind){
            swap(word[i++], word[ind--]);
        }
        
        return word;
    }
};