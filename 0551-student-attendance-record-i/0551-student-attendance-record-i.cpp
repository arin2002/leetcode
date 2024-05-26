class Solution {
public:
    bool checkRecord(string s) {
        int total = 0, temp = 0;
        
        for(auto &it: s){
            if(it == 'A'){
                total++;
            }
            
            if(it == 'L'){
                temp++;
            }
            else
                temp = 0;
            
            if(total == 2 || temp == 3)
                return false;
        }
        
        return true;
    }
};