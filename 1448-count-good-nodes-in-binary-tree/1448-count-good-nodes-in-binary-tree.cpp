class Solution {
public:
    int ans = 0;
    
    void f (TreeNode *root, int maxi){
        if(root == NULL){
            return;
        }
        
        if(root->val >= maxi){
            ans++;
        }
        
        f(root->left, max(root->val,maxi));
        f(root->right, max(root->val,maxi));
    }
    
    int goodNodes(TreeNode* root) {
        f(root, root->val);
        return ans;
    }
};