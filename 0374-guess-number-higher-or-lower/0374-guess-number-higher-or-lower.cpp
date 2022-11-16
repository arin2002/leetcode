class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n;
        
        while(i<=j){
            int mid = i +(j-i)/2;
            
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == -1){
                j = mid-1;
            }
            else
                i = mid+1;
        }
        
        return 0;
    }
};