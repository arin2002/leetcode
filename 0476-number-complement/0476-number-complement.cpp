class Solution {
public:
    int findComplement(int num) {
        int ans = 0, turn = 0;
        
        while(num>0){
            if(!(num%2)){
                ans += pow(2,turn);
            }
            
            turn++;
            num /= 2;
        }
        
        return ans;
    }
};