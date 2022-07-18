/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode *ans = NULL;
    
    void helper(TreeNode *root2, TreeNode* k)
    {
        if(root2==NULL)
            return;
        
        if(root2->val == k->val)
            ans = root2;
        
        helper(root2->left, k);
        helper(root2->right, k);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        helper(cloned,target);
        return ans;
    }
};