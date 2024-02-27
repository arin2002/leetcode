class Solution {
public:
    int maxi = 0;
    int helper(TreeNode* root)
    {
        if(root== NULL)
            return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        maxi = max(maxi,l+r);
        return 1+max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        helper(root);
        return maxi;
    }
};