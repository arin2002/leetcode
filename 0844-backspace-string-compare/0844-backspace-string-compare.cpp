class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        stack<char> st,st1;
        for(int i = 0; i<n; i++){
            if(!st.empty() && s[i] == '#'){
                st.pop();
            }
            else if(s[i] != '#'){
                st.push(s[i]);
            }
        }
        
        for(int i = 0; i<m; i++){
            if(!st1.empty() && t[i] == '#'){
                st1.pop();
            }
            else if(t[i] != '#'){
                st1.push(t[i]);
            }
        }
        
        if(st.size() != st1.size())
            return 0;
        
        while(!st.empty()){
            if(st.top() != st1.top())
                return 0;
            
            st.pop(); st1.pop();
        }
        
        return 1;
    }
};