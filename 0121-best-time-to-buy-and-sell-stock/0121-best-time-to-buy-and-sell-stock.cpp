class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, ans = 0;
        
        for(auto it: prices){
            mini = min(mini,it);
            
            ans = max(ans,it-mini);
        }
        
        return ans;
    }
};