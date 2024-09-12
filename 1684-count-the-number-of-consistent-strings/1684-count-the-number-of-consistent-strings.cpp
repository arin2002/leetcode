class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(allowed.begin(),allowed.end());
        int ans = 0;
        for(auto &it: words){    
            int flag = 1;
            
            for(auto &i: it){
                if(st.find(i) == st.end()){
                    flag = 0;
                    break;
                }
            }
            
            if(flag){
                ans++;
            }
        }
        
        return ans;
    }
};