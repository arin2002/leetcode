class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,pair<string,int>> ump;
        
        for(auto &it: words){
            vector<int> v;
            for(int i = 0; i<it.size()-1; i++){
                v.push_back(it[i+1]-it[i]);
            }
            
            if(ump.find(v) != ump.end()){
                
            }
            ump[v] = {it,ump[v].second+1};
        }
        
        for(auto [a,b]: ump){
            if(b.second == 1){
                return b.first;
            }
        }
        
        return "";
    }
};