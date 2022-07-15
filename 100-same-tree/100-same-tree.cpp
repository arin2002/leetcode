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
    int helper(TreeNode *p, TreeNode *q)
    {
        if(!p && !q)
            return 1;
        
        if(!p || !q)
            return 0;
        
        int l = helper(p->left,q->left);
        int r = helper(p->right, q->right);
        
        if(l==1 && r==1 && p->val==q->val)
            return 1;
        
        return 0;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p,q);
    }
};