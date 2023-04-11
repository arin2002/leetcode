class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        if(s.find('*') == -1)
            return s;
        
        for(auto &it: s){
            if(it == '*'){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(it);
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};