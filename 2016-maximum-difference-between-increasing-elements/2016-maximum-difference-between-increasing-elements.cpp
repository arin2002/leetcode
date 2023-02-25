class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, mini = INT_MAX;
        
        for(auto it : nums){ 
            // cout<<it<<" "<<mini<<" ";
            // cout<<it-mini<<endl;
            if(it != mini)
                ans = max(ans,it-mini);
            mini = min(it,mini);
        }
        
        return ans;
    }
};