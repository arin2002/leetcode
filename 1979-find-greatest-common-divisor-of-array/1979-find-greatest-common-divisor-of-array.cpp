class Solution {
public:
    
    
    int gcd(int i, int j){
        if(i == 0)
            return j;
        
        return gcd(j%i,i);
    }
    
    
    int findGCD(vector<int>& nums) {
        int mini = 1001, maxi = 0;
        int ans = 0;
        
        for(auto i: nums){
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        cout<<mini<<maxi;
        ans = gcd(mini,maxi);
        return ans;
    }
};