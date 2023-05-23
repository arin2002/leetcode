class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        
        int temp = 0;
        for(auto &it: gain){
            temp += it;
            ans = max(ans,temp);
        }
        
        return ans;
    }
};