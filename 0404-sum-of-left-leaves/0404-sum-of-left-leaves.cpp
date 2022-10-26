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
    void f(TreeNode *root, int val){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            
            if(val == 0)
            ans += root->val;
            return;
        }
        
        f(root->left,0);
        f(root->right,1);
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        // if(root->left == NULL && root->right == NULL)
        //     return 0;
        
        f(root,-1);
        return ans;
    }
};