class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(),candies.end());
        vector<bool> ans(candies.size());
        for(int i = 0; i<candies.size(); i++){
            int it = candies[i]+extraCandies;
            if(it>=maxi){
                ans[i] = 1;
            }
        }
        
        return ans;
    }
};