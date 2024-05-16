/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool evaluateTree(TreeNode* root) { 
        stack<int> st;
        
        function<void(TreeNode*)> solve = [&](TreeNode* root){
            if(!root)
                return;
            
            if((root->left == NULL) && (root->right == NULL)){
                st.push(root->val);
                return;
            }
            
            solve(root->left);
            solve(root->right);
            
            if(root->val == 2){
                int a = st.top();
                st.pop();
                
                int b = st.top();
                st.pop();
                
                st.push(a|b);
            }
            else{
                int a = st.top();
                st.pop();
                
                int b = st.top();
                st.pop();
                
                st.push(a&b);
            }
            
        };
        
        
        solve(root);
        return st.top();
    }
};