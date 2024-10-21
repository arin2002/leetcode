class Solution {
public:
    int maxUniqueSplit(string s) {

        if(s.size() == 1) return 1;
        int ans = 1;
        int lm = (1<<(s.size()-1));
        vector<bool> bnum(s.size()-1,0);
        unordered_set<string> st;
        string ts;
        bool tocnt;
        int ocnt =0;
        for(int i=lm-1;i>=0;i--){
            st.clear();
            ocnt =0;
            int tmp =i;
            // generating bit mask
            for(int j=1;j<s.size();j++){
                bnum[s.size()-1-j]=tmp%2;
                tmp = tmp/2;
                if(bnum[s.size()-1-j]) ocnt++;
            }
            if(ans>ocnt+1) continue;

            // spliting string based on mask
            ts = "";
            ts.push_back(s[0]);
            tocnt = true;
            for(int k =0;k<bnum.size();k++){
                if(bnum[k]){
                    if(st.find(ts) == st.end()){
                        st.insert(ts);
                    } else {
                        tocnt = false;
                        break;
                    }
                    ts = s[k+1];
                }else{
                    ts.push_back(s[k+1]);
                }
            }
            
            // updated only if all are unique. 
            if(tocnt) {
                // need to check for last splited string.
                if(st.find(ts) == st.end()){
                    st.insert(ts);
                    ans = max(ans,(int)st.size());
                } else {
                    tocnt = false;
                }
            }
        }
        return ans;
    }
};
