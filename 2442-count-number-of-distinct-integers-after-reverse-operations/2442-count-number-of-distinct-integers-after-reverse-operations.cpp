class Solution {
public:
    
    int rev(int n){
        
        int ans = 0;
        while(n>0){
            ans = ans * 10 + n%10;
            n/=10;
        }
        cout<<ans<<" ";
        return ans;
    }
    
    
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ump;
        for(auto i : nums){
            ump.insert(i);
            ump.insert(rev(i));
        }
        
        return ump.size();
    }
};