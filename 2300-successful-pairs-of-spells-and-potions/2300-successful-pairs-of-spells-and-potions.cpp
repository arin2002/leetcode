class Solution {
public:
    
    int solve(long long it, long long success, vector<int>& potions){
        int l = 0, r = potions.size()-1, n = potions.size();
        
        int ans = n;
        while(l<=r){
            int mid = l + (r-l)/2;
            long k = 1LL* potions[mid] * it;
            
            if(k < success){
                l = mid+1;
            }
            else{
                ans = mid;
                r = mid-1;
            }
        }
        
        return n-ans;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        
        for(auto &it: spells){
            ans.push_back(solve(it,success,potions));
        }
        
        return ans;
    }
};