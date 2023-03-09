class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        
        int swaps = 0;
        for(auto &it:s){
            if(it == '['){
                open++;
            }
            else{
                if(open>0)
                    open--;
            }
        }
        
        return (open+1)/2;
    }
};