class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans;
        n++; 
        
        long long val = 1;
        for(int i = 0; i<n; i++){
            if(i == 0 || i == n-1){
                ans.push_back(1);
                continue;
            }
            
            val *= (n-i);
            val /= i;
            ans.push_back(val);
        }
        
        return ans;
    }
};