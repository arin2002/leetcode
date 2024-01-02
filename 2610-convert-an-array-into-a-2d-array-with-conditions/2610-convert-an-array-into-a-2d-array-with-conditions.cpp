class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> ump;
        vector<vector<int>> ans;
        
        for(auto &it: nums){
            ump[it]++;
        }
                
        while(1){
            vector<int> temp;
            for(auto &[a,b]: ump){
                if(b!= 0){
                    temp.push_back(a);
                    b--;
                }
            }
            
            if(temp.size()){
                ans.push_back(temp);
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};
