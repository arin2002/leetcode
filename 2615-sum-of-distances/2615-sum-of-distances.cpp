#define ll long long

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // for storing indexes
        unordered_map<ll,vector<ll>> ump;
        ll n = nums.size();
        vector<ll> ans(n);
        
        for(int i = 0; i<n; i++){
            ump[nums[i]].push_back(i);
        }
        
        // traverse in map
        // it will be o(n)
        
        for(auto &it: ump){
            // use prefix sum concept for finding indexes
            vector<ll> v = it.second;
            
            ll prefixSum = 0, total = 0, left = 0, right = 0;
            ll leftPart = 0, rightPart = 0, m = v.size();
            for(auto &i: v){
                total += (ll)i;
            }
            // now in this array find for all index where it occuring
            // this is an obervation question
            // like 1 2 3 4 5 hai
            // for index 3 apna ans = 2*k - (1+2) + 2*k - (4+5)
            // clearly prefix sum can be seen
            for(int i = 0; i<v.size(); i++){
                prefixSum += v[i];
                left = prefixSum - v[i];
                right = total - prefixSum;
                
                leftPart = (v[i]*i) - left;
                rightPart = right - (m-i-1) * v[i];
                // cout<<it.first<<" "<<v[i]<<" "<<leftPart<<" "<<rightPart<<endl;
                ans[v[i]] = leftPart + rightPart;
            }
        }
        
        return ans;
    }
};