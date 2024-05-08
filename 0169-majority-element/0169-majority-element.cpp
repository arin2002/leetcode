class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore voting algo
        int candidate = -1, count = 0;
        
        for(auto &it: nums){
            if(candidate == -1 || count == 0){
                candidate = it;
                count = 1;
            }
            else{
                if(candidate == it)
                    count++;
                else
                    count--;
            }
        }
        
        // verifaction step not needed in this
        return candidate;
    }
};