class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>> v;
        unordered_map<char,int> ump;
        
        for(auto it : s){
            ump[it]++;
        }
        
        for(auto [i,j] : ump){
            v.push_back({j,i});
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        string ans;
        for(auto [i,j] : v){
            while(i){
                ans+=j;
                i--;
            }
        }
        
        return  ans;
    }
};