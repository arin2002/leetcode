class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string,vector<string>> ump;
        
        for(auto &it: strs){
            string s = it;
            sort(s.begin(),s.end());
            
            ump[s].push_back(it);
        }
        
        for(auto &[a,b]: ump){
            ans.push_back(b);
        }
        
        return ans;
    }
};