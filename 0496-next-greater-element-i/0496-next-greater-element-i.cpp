class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& num2) {
        int n = num2.size();
        unordered_map<int,int> ump;
        stack<int> st;
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top()<num2[i])
                st.pop();
            
            if(st.empty())
                ump[num2[i]] = -1;
            else
                ump[num2[i]] = st.top();
            
            st.push(num2[i]);
        }
        
        for(auto &it: nums1){
            it = ump[it];
        }
        
        return nums1;
    }
};