class Solution {
public:
    
    int sum(string &s){
        string num = "";
        for(auto it : s){
            num += to_string(it-'a');
        }
        
        return stoi(num);
    }
    
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        int a = sum(firstWord);
        int b = sum(secondWord);
        int c = sum(targetWord);
        
        int d = a+b;
        
        if(d == c)
            return true;
        
        return false;
    }
};