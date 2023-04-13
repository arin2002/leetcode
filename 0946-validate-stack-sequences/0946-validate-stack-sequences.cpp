class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int top = 0, start = 0, n = pushed.size();
        
        for(int i = 0; i<n ; i++){
            // push in array
            pushed[top++] = pushed[i];
            
            while(top>=1 && popped[start] == pushed[top-1]){
                top--;
                start++;
            }
        }
        
        return top == 0;
    }
};