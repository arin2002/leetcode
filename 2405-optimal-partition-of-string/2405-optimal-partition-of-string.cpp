class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> ump;
        
        int ans = 0;
        for(auto it : s){
            if(ump.find(it) != ump.end()){
                ans++;
                ump.clear();
            }
            ump[it]++;
        }
        
        if(ump.size())
            ans++;
        
        return ans;
    }
};