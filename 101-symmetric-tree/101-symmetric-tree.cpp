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
    bool ans = false;
    
    bool helper(TreeNode* rootL, TreeNode *rootR)
    {
        if(rootL == NULL && rootR == NULL)
            return true;
        
        if(rootL == NULL || rootR==NULL)
            return false;
        
        // if(rootL->left == NULL || rootR->right == NULL)
        //     return false;
        
        if(rootL->val != rootR->val)
            return false;
        
        return helper(rootL->right,rootR->left) && helper(rootL->left,rootR->right);
        
        // return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        // if(root->left == NULL || root->right == NULL)
        //     return false;
        
        return helper(root->left,root->right);
    }
};