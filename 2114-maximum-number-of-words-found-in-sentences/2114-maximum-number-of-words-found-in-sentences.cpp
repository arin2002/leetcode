class Solution {
public:
    int mostWordsFound(vector<string>& nums) {
        int ans = 1;
        
        for(auto &it : nums){
            int counts = count(it.begin(),it.end(),' ');
            ans = max(counts+1,ans);
        }
        
        return ans;
    }
};