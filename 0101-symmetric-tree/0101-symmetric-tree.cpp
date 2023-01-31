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
    
    bool solve(TreeNode* rootL, TreeNode* rootR){
        if(!rootL && !rootR)
            return 1;
        
        if(!rootL || !rootR)
            return 0;
        
        if(rootL->val != rootR->val){
            return 0;
        }
        
        return solve(rootL->left,rootR->right) & solve(rootL->right,rootR->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};