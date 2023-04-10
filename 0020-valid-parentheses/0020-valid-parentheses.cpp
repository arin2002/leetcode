class Solution {
public:
    
    bool check(stack<char> &st, char &it){
        if(st.empty())
            return false;
        
        char t = st.top();
        if(it == ')' && t == '(')
            return true;
        
        if(it == '}' && t == '{')
            return true;
        
        if(it == ']' && t == '[')
            return true;
        
        return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        
        for(auto &it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }
            else{
                if(check(st,it)){
                    st.pop();
                }
                else
                    return false;
            }
        }
        
        if(st.size())
            return false;
        
        return true;
    }
};