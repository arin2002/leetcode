class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even, odd, ans;
        
        for(auto &it: nums){
            if(it%2){
                odd.push_back(it);
            }
            else{
                even.push_back(it);
            }
        }
        
        int j = 0, k = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i%2){
                ans.push_back(odd[j++]);
            }
            else{
                ans.push_back(even[k++]);
            }
        }
        
        return ans;
    }
};