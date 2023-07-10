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
    
    int ans = INT_MAX;
    
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        
        if(!root->left){
            return 1+solve(root->right);
        }
        else if(!root->right){
            return 1+solve(root->left);
        }
        
        int l = 1+solve(root->left);
        int r = 1+solve(root->right);
        
        cout<<l<<" "<<r<<endl;
        return min(l,r);
    }
    
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};