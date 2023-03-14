class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        string ans = "";
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i] = '.';
                }
            }
            if(s[i] == '(')
                st.push(i);
        }
        
        // if(!st.empty())
        while(!st.empty()){
            s[st.top()] = '.';
            st.pop();
        }
        
        for(auto &it :s){
            if(it != '.')
                ans += it;
        }
        return ans;
    }
};