class Solution {
public:
    int minPartitions(string s) {
        
        int ans = 0;
        
        for(auto it : s){
            if(ans == 9)
                return ans;
            
            int n = it-'0';
            ans = max(ans,n);
        }
        
        return ans;
    }
};