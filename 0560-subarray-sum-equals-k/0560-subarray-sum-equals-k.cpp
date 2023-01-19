class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        
        int sum = 0,  count = 0;
        // for handling  i = 0 test case;
        ump[0] = 1;
        
        for(auto it : nums){
            sum += it;        
            // for finding
            auto i = ump.find(sum-k);
            
            if(i!= ump.end()){
                count += i->second;
            }
            
            // store now
            // map for storing prefix sum
            ump[sum]++;
        }
        
        return count;
    }
};