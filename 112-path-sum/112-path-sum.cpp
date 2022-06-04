class Solution {
public:
    bool ans = false;
    void helper(TreeNode* root, int targetSum)
    {
        if(root==NULL)
            return;
        
        if(targetSum==root->val && root->left==NULL && root->right==NULL)
        {
            ans = true;
            return;
        }
        
        helper(root->left,targetSum-root->val);
        helper(root->right,targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       helper(root,targetSum);
        return ans;
        
    }
};
