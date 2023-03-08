class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> prefix(n);
        
        unordered_set<char> st;
        int i = 0;
        for(auto &it : s){
            st.insert(it);
            prefix[i++] = st.size(); 
        }
        
        st.clear(); int cnt = 0;
        for(int i = n-1; i>=1; i--){
            st.insert(s[i]);
            
            cout<<st.size()<<" "<<prefix[i]<<endl;
            if(st.size() == prefix[i-1])
                cnt++;
        }
        
        return cnt;
    }
};