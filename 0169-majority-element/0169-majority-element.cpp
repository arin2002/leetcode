class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candi = 0;
        
        for(auto &it : nums){
            if(count == 0){
                candi = it;
            }
            
            if(candi == it)
                count++;
            else
                count--;
        }
        
        return candi;
    }
};