class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans;
        
        for(auto &it: s){    
            if(st.empty()){
                st.push(it);
                continue;
            }
            
            int a = abs(it-st.top());
            
            if(a == 32){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};