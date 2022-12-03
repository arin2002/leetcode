class Solution {
public:
    
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first)
            return a.second > b.second;
        
        return b.first>a.first;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;
        
        for(auto it : nums)
            ump[it]++;
        
        vector<pair<int,int>> v;
        for(auto [i,j] : ump){
            v.push_back({j,i});
        }
        
        int k = 0;
        sort(v.begin(),v.end(),cmp);
        for(auto [i,j] : v){
            while(i--){
                nums[k++] = j;
            }
        }
        
        return nums;
    }
};