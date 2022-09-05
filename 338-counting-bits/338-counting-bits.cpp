class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        
        if(n==0)
            return ans;
        
        for(int i = 1; i<=n; i++){
            int count = 0;
            
            int k = i;
            while(k != 0){
                
                if(k & 1)
                    count++;
                
                k = k>>1;
            }
            
            ans.push_back(count);
        }
        
        return ans;
        
    }
};