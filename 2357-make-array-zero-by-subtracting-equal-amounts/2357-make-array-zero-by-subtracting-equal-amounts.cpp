class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto it: nums){
            if(it == 0)
                continue;
            
            s.insert(it);
        }
        return s.size();
    }
};