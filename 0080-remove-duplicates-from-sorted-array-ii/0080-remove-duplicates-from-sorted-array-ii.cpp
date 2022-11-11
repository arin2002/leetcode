class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        map<int,int> ump;
        
        for(auto it : nums)
            ump[it]++;
        
        int i = 0;
        for(auto it : ump){
            //cout<<it.second<<" "<<it.first<<" ";
            if(it.second >= 2){
                nums[i++] = it.first;
                nums[i++] = it.first;
            }
            
            else if(it.second == 1){
                nums[i++] = it.first;
            }

        }
        return i;
    }
};