class Solution {
public:
    
    void fun(stack<long long> &st, string ch){
        long long b = st.top();
        st.pop();
        long long a = st.top();
        st.pop();
        
        if(ch == "+"){
            st.push(a+b);
        }
        else if(ch == "-")
            st.push(a-b);
        else if(ch == "/")
            st.push(a/b);
        else
            st.push(a*b);
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        int a,b;
        for(auto &it : tokens){
            if(it == "+" || it == "/" || it == "-" || it == "*"){
                fun(st,it);
            }
            else
            st.push(stoi(it));
        }
        
        //cout<<st.size();
        return st.top();
    }
};