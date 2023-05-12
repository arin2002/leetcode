class Solution {
public:
    
    void leftsmaller(int i, stack<int> &st, vector<int> &leftSmaller,vector<int>& heights){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        
        if(st.empty()){
            leftSmaller[i]=0;
        }
        else{
            leftSmaller[i] = st.top()+1;
        }
        
        st.push(i);
    }
    
    void rightsmaller(int i, stack<int> &st, vector<int> &rightSmaller,vector<int>& heights){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        
        if(st.empty()){
            rightSmaller[i] = heights.size()-1;
        }
        else{
            rightSmaller[i] = st.top()-1;
        }
        
        st.push(i);
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = INT_MIN;
        
        // concept of left smaller and right smaller
        // for each index we see
        // for that index ans[i] = (leftsmaller-rightsmaller)*heighy[i]
        // width is this leftsmall - rightsmall
        
        stack<int> st;
        
        vector<int> leftSmaller(n), rightSmaller(n);
        for(int i = 0; i<n; i++){
            leftsmaller(i,st,leftSmaller,heights);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1; i>=0; i--){
            rightsmaller(i,st,rightSmaller,heights);
        }
        
        for(int i = 0; i<n; i++){
            int temp_ans = (rightSmaller[i]-leftSmaller[i]+1)*heights[i];
            ans = max(ans,temp_ans);
        }
        
        
        return ans;
    }
};