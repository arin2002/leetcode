class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int prev = -1;
        while(n){
            
            int curr = n&1;
            if(prev == 0){
                if(curr == 0)
                    return false;
            }
            
            else if(prev == 1){
                if(curr == 1)
                    return false;
            }
            
            prev = curr;
            n >>=1;
        }
        
        return true;
    }
};