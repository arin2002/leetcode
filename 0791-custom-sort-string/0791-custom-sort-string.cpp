class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ump;
        string ans;
        for(auto &it : s){
            ump[it]++;
        }
        
        for(auto &it : order){
            if(ump.find(it) != ump.end()){
                int n = ump[it];
                string temp(n,it);
                ans += temp;
                ump.erase(it);
            }
        }
        
        for(auto &it : ump){
            int n = it.second;
            string temp(n,it.first);
            ans += temp;
        }
        
        return ans;
    }
};