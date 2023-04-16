class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        int n = path.size();
        for(int i = 0; i<n; i++){
            if(path[i] == '/')
                continue;
            
            string word;
            while(i<n && path[i] != '/'){
                word += path[i];
                i++;
            }
            
            if(word == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                if(word != "."){
                    st.push(word);
                }
            }
        }
        
        string ans;
        
        if(st.empty())
            return "/";
        
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return  ans;
    }
};