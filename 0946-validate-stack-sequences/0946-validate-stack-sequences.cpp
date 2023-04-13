class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int start = 0, n = popped.size(), i = 0;
        
        stack<int> st;
        for(auto &it : pushed){
            st.push(it);
            
            while(!st.empty() && start<n && st.top() == popped[start]){
                start++;
                st.pop();
            }
        }
        
        return st.empty();
    }
};