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
    int ans = 0;
    void f(TreeNode *root, TreeNode *prev){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            // cout<<root->val<<" ";
            
            if(prev->right != root)
            ans += root->val;
            return;
        }
        
        f(root->left,root);
        f(root->right,root);
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return 0;
        
        f(root,root);
        return ans;
    }
};