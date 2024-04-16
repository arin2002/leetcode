class Solution {
public:
    string removeKdigits(string num, int k) {
        // stack<char> st;
        string ans;
        
        // monotonic
        for(auto &it: num){
            while(!ans.empty() && k>0 && ans.back()> it){
                // st.pop();
                ans.pop_back();
                k--;
            }
            
            if(ans.empty() && it == '0'){
                continue;
            }
            
            ans.push_back(it);
        }
        
        while(k-- && !ans.empty())
            ans.pop_back();
        
//         while(!st.empty()){
//             ans += st.top();
//             st.pop();
//         }
        
        // int end = 0;
        // for(int i = ans.size()-1; i>=0; i--){
        //     if(ans[i] != '0'){
        //         end = i;
        //         break;
        //     }
        // }
        
        // int start = ans.size();
        // for(int i = 0; i<ans.size(); i++){
        //     if(ans[i] != '0'){
        //         start = i;
        //         break;
        //     }
        // }
        
//         ans = ans.substr(0,end+1);
//         reverse(ans.begin(),ans.end());
        
        // ans = ans.substr(start);
        
        if(ans == "")
            return "0";
        
        return ans;
    }
};