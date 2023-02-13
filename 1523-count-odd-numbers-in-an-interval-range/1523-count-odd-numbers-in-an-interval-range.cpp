class Solution {
public:
    int countOdds(int low, int high) {
        
        if(low == high){
            return low%2;
        }
        
        if(low%2 == 0)
            low = low + 1;
        
        
        int count = 0;
        for(int i = low; i<=high; i+=2){
            if(i%2)
                count++;
        }
        
        return count;
    }
};