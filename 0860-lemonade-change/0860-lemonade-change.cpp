class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, tens = 0;
        
        for(auto &it: bills){
            if(it == 5){
                five++;
            }
            else{
                if(it == 20){
                    if(tens && five){
                        tens--;
                        five--;
                        
                    }
                    else if(five >= 3){
                        five -=3;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(five)
                        five--;
                    else
                        return false;
                    
                    tens++;
                }
            }
        }
        
        return true;
    }
};