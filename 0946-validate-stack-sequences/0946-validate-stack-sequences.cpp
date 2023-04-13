class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int start = 0, n = popped.size(), i = 0;
        
        stack<int> st;
        while(i<n){
            if(!st.empty() && start<n && st.top() == popped[start]){
                st.pop();
                start++;
            }
            else{
                st.push(pushed[i]);
                i++;
            }
        }
        
        if(st.empty())
            return true;
        
        while(!st.empty() && start<n && st.top() == popped[start]){
            start++;
            st.pop();
        }
        
        return st.empty();
    }
};