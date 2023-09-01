class Solution {
public:
    
    int solve(int n){
        int count = 0;
        while(n){
            int bit = n&1;
            if(bit) count++;
            n>>=1;
        }
        
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int>  ans;
        for(int i = 0; i<=n; i++){
            ans.push_back(solve(i));
        }
        
        return ans;
    }
};