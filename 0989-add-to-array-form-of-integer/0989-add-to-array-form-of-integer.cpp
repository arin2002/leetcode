class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> ans;
        
        int i = nums.size()-1, carry = 0;
        while(i>=0 || k || carry){
            int val = 0;
            
            if(i>=0)
                val = nums[i] + k%10 + carry;
            else
                val = k%10 + carry;
            
            ans.push_back(val%10);
            
            carry =  (val)/10;
            k/=10;
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};