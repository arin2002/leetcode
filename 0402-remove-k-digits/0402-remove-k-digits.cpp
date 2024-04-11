class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        // monotonic
        for(auto &it: num){
            while(!st.empty() && k>0 && st.top()> it){
                st.pop();
                k--;
            }
            
            st.push(it);
        }
        
        while(k-- && !st.empty())
            st.pop();
        
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        int end = 0;
        for(int i = ans.size()-1; i>=0; i--){
            if(ans[i] != '0'){
                end = i;
                break;
            }
        }
        
        ans = ans.substr(0,end+1);
        reverse(ans.begin(),ans.end());
    
        
        if(ans == "")
            return "0";
        
        return ans;
    }
};