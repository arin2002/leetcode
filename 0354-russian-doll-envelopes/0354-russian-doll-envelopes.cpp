class Solution {
public:
    
    bool static cmp (vector<int> a, vector<int> b){
        if(a[0] == b[0])
            return a[1]>b[1];
        
        return a[0]<b[0];
    }
    
    int solve(vector<int> &nums){
        vector<int> temp;
        int n = nums.size();
        temp.push_back(nums[0]);
        
        for(int i = 1; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
            }
        }
        
        return temp.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& nums) {        
        sort(nums.begin(),nums.end(),cmp);
        
        vector<int> v;
        
        // 1st wala to sorted ki help se ho gyaa
        // 2nd wale ne apun ne lcs laga diya ans nikalne ke liye
        // max kitne ho sakhte bas
        for(auto &it: nums){
            v.push_back(it[1]);
        }
        
        return solve(v);
    }
};