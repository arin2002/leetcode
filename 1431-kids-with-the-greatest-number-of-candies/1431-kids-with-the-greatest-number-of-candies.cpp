class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ext) {
        vector<bool> ans;
        
        int maxi = 0;
        for(auto it : candies){
             maxi = max(it,maxi);
        }
        
        for(auto it : candies){
            int num = it+ ext;
            
            if(num >= maxi)
                ans.push_back(1);
            else
                ans.push_back(0);
            
        }
        
        return ans;
    }
};