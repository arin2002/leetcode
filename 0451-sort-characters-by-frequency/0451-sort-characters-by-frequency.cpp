class Solution {
public:
    string frequencySort(string s) {
        // vector<int> v(26);
        unordered_map<char,int> v;
        
        for(auto &it: s){
            v[it]++;
        }
        
        sort(s.begin(),s.end(),[&](auto a, auto b){
            if(v[a] == v[b]){
                return a<b;
            }
            
            return v[a]>v[b];
        });
        
        return s;
    }
};