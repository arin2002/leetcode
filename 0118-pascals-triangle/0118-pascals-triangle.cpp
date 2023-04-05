class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        for(int i = 1; i<=n; i++){
            int val = 1;
            vector<int> temp;
            for(int j = 0; j<i; j++){
                if(j == 0 || j == i){
                    temp.push_back(1);
                    continue;
                }
                val *= (i-j);
                val /= j;
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};