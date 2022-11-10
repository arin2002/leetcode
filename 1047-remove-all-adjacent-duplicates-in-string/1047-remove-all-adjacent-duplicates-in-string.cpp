class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for(auto it : s){
            if(!st.empty() && it == st.top()){
                st.pop();
                continue;
            }
            
            st.push(it);
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};