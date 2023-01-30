class Solution {
public:
    
    int maxi = INT_MIN;
    
    int solve(TreeNode *root){
        if(!root)
            return 0;
        
        // 0 taken to neglect -ve paths
        int leftSum = max(0,solve(root->left));
        int rightSum = max(0,solve(root->right));
        
        maxi = max(maxi,leftSum+rightSum+root->val);
        
        return root->val+max(leftSum,rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};