class Solution {
public:
    int sum = 0;
    void fun(TreeNode* root){
        if(root){
            fun(root->right);
            sum += root->val;
            root->val = sum;
            fun(root->left);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        fun(root);
        return root;
    }
};
