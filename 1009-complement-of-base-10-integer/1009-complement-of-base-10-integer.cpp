class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int> bits;
        
        if(n == 0)
            return 1;
        
        while(n){
            int bit = n&1;
            
            if(bit)
                bits.push_back(0);
            else
                bits.push_back(1);
            
            n >>=1;
        }
        
        int ans = 0, i = 0;
        for(auto it : bits){
            if(it == 1){
                ans = ans + pow(2,i);
            }
            i++;
        }
        return ans;
    }
};