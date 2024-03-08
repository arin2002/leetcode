class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101);
        int maxi = 0, freq = 0;
        
        for(auto &it: nums){
            v[it]++;
            int f = v[it];
            
            if(f>maxi){
                maxi = f;
                freq = f;

            }
            else if(f == maxi){
                freq += f;
            }
        }
        
        return freq;
    }
};