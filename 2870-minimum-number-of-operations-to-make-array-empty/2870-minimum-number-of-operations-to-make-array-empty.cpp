class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size(), ans = 0;
        
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(auto [a,b]: mp){
            cout<<a<<" "<<b<<endl;
            // ceil trick (a+b-1)/b
            if(b == 1)
                return -1;
            
            ans += ceil(b/3.0);
        }
        
        return ans;
    }
};