class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        
        unordered_map<int,int> ump;
        
        for(auto it : nums){
            ump[it]++;
        }
        
        for(int i = 1; i<=nums.size(); i++){
            if(ump.find(i) == ump.end())
                v.push_back(i);
        }
        
        return v;
    }
};