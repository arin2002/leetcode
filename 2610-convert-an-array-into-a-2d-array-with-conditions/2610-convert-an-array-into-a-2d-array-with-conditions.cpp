class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> ump;
        unordered_set<int> st;
        for(auto &it: nums){
            ump[it]++;
            st.insert(it);
        }
        
        vector<vector<int>> ans;
        
        while(st.size()){
            vector<int> temp;
            for(auto &it: ump){
                if(it.second == 0){
                    if(st.find(it.first) != st.end()){
                        st.erase(it.first);
                    }
                    continue;
                }
                temp.push_back(it.first);
                it.second--;
            }
            if(temp.size() != 0)
            ans.push_back(temp);
        }
        
        return ans;
    }
};