class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0], maxi = arrays[0].back();
        int ans = 0;
        
        for(int i = 1; i<arrays.size(); i++){
            int a = arrays[i][0], b = arrays[i].back();
            
            int local_maxi = max(abs(b-mini),abs(maxi-a));
            
            ans = max(ans,local_maxi);
            mini = min(mini,a);
            maxi = max(maxi,b);
        }
        
        return ans;
    }
};