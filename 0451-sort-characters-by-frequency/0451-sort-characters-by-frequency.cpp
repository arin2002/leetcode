class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> ump;
        
        for(auto it : s){
            ump[it]++;
        }
        
        vector<pair<int,char>> vp;
        
        for(auto it : ump){
            vp.push_back({it.second,it.first});
        }
        
        sort(vp.begin(),vp.end(),greater<pair<int,char>>());
        
        string ans;
        for(auto it : vp){
            string temp(it.first,it.second);
            ans+=temp;
        }
        
        return ans;
    }
};