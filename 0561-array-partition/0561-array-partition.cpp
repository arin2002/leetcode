class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        int sum = 0;
        
        vector<int> v(20001,0);
        
        for(auto it : nums){
            v[it+10000]++;
        }
        
        int count = 0, i = 0;
        
        while(i<20001){
            if(v[i] != 0){
                if(count%2 == 0)
                    sum += (i-10000);
                
                count++;
                v[i]--;
            }
            else
                i++;
        }
        return sum;
    }
};