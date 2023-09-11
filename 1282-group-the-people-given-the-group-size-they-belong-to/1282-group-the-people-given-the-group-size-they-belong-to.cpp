class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> ump;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            ump[nums[i]].push_back(i);
            
            if(ump[nums[i]].size() == nums[i]){
                ans.push_back(ump[nums[i]]);
                ump[nums[i]].clear();
            }
        }
        
//         for(auto [a,b]: ump){
//             int size = b.size();
            
//             int i = 0, m = a;
//             while(size){
//                 vector<int> temp;
//                 cout<<m<<" "<<size<<endl;
//                 for(int j = 0; j<m; j++,size--){
//                     temp.push_back(b[i++]);
//                 }
                
//                 ans.push_back(temp);
//             }
//         }
        
        return ans;
    }
};