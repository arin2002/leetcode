class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<char> st;
        
        for(auto it : s){
            if(it == ')'){
                string temp;
                while(st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(auto &a : temp)
                    st.push(a);
            }
            else
                st.push(it);
        }
        
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};