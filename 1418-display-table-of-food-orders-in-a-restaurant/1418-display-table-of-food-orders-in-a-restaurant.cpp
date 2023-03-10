class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        set<string> s;
        map<int,unordered_map<string,int>> mp;
        
        for(auto it : orders){
            s.insert(it[2]);
            mp[stoi(it[1])][it[2]]++;
        }
        
        vector<string> first;
        first.push_back("Table");
        for(auto it : s)
            first.push_back(it);
        
        ans.push_back(first);
        
        for(auto &it : mp){
            vector<string> temp;
            temp.push_back(to_string(it.first));
            
            for(auto &i: s){
                if(it.second.find(i) == it.second.end())
                    temp.push_back("0");
                
                else{
                    temp.push_back(to_string(it.second[i]));
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};