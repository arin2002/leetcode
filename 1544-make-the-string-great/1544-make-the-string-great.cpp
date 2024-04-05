class Solution {
public:
    string makeGood(string s) {
        // stack<char> st;
        // use ans as stack in this 
        string ans;
        
        for(auto &it: s){    
            if(ans.empty()){
                // st.push(it);
                ans.push_back(it);
                continue;
            }
            
            int a = abs(it-ans.back());
            
            if(a == 32){
                // st.pop();
                ans.pop_back();
            }
            else{
                // st.push(it);
                ans.push_back(it);
            }
        }
        
        // while(!st.empty()){
        //     ans += st.top();
        //     // ans = st.top()+ans;
        //     st.pop();
        // }
        
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};