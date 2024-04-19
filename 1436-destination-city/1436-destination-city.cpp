class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> ump;
        
        for(auto &it: paths){
            ump[it[0]] = it[1];
        }
        
        function<string(string)> dfs = [&](string city){
            if(ump.find(city) == ump.end())
                return city;
              
            return dfs(ump[city]);
        };
        
        return dfs(paths[0][0]);
    }
};