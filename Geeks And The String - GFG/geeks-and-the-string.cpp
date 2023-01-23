//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> st;
        
        for(auto it : s){
            if(st.empty()){
                st.push(it);
            }
            else{
                char prev = st.top();
                if(prev == it){
                    st.pop();
                }
                else{
                    st.push(it);
                }
            }
        }
        
        if(st.empty()){
            return  "-1";
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


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends