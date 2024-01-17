class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> st;
        unordered_map<int,int> ump;
        
        for(auto &it: arr){
            ump[it]++;
        }
        
        for(auto &[a,b]: ump){
            if(st.find(b) != st.end())
                return 0;
            
            st.insert(b);
        }
        
        return 1;
    }
};