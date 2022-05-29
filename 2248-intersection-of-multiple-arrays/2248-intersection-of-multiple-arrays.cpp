class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums){
        unordered_map<int,int> m;
        int r=nums.size();
        for(int i=0;i<r;i++){
            for(int j=0;j<nums[i].size();j++){
                m[nums[i][j]]++;  // For counting frequency of every element in whole matrix
            }
        }
        vector<int> ans;
        for(auto i:m){
            if(i.second==r) ans.push_back(i.first);  // Pushing only those elements with frequency equal to no. of rows
        }
        sort(ans.begin(),ans.end());  // Sorting the array as answer is desired in the ascending order
        return ans;
    }
};
