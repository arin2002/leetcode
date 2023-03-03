class Solution {
public:
    
    
    bool check(stack<char> st, string &t){
        int j = t.size()-1;
        
        while(j>=0 && t[j] == st.top()){
            st.pop();
            j--;
        }
        
        return j == -1;
    }
    
    string removeOccurrences(string s, string t) {
        stack<char> st;
        
        for(auto it : s){
            st.push(it);
            
            if(st.size() >= t.size()){
                if(check(st,t)){
                    for(int i = 0; i<t.size(); i++)
                        st.pop();
                }
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};