class Solution {
public:
    int mostWordsFound(vector<string>& nums) {
        int ans = 1;
        
        for(auto it : nums){
            string s = it;
            int count = 1;
            for(auto i :s){
                if(i == ' ')
                    count++;
            }
            
            ans = max(count,ans);
        }
        
        return ans;
    }
};