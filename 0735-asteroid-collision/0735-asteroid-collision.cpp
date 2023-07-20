class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        
        for(auto &it: nums){
            int c  = 0;
            
            while(!st.empty() && st.top() > 0 && it<0){
                
                if(abs(it)>abs(st.top())){
                    st.pop();
                    continue;
                }
                
                else if(abs(it) == abs(st.top())){
                    st.pop();
                }
                
                c = 1;
                break;
            }
            if(c == 0)
                st.push(it);
            
            // cout<<st.top()<<" ";
        }
        while(!st.empty()){ 
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};