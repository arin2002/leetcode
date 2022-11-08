class Solution {
public:
    string makeGood(string s) {
//         for(int i = 0; i<s.length()-1; i++){
//             if((s[i] >= 'a' && s[i] <= 'z' && s[i+1] >= 'A' && s[i] <= 'Z')){
                
//             }
//         }
        
        // int i = 0;
        // while(i<s.length()-1){
        //     if(((s[i] >= 'a' && s[i] <= 'z') && (s[i+1] >= 'A' && s[i+1] <= 'Z'))){
        //         s.erase(i,i+1);
        //         //cout<<s<<endl;
        //         i = 0;
        //     }
        //     else
        //         i++;
        //     cout<<i<<" ";
        //     cout<<s<<endl;
        // }
        
        
        stack<char> st;
        
        for(auto i :s){
            if(!st.empty() && abs(i-st.top()) == 32)
                st.pop();
            else
                st.push(i);
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