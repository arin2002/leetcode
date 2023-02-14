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
    
    TreeNode * solve(TreeNode * root){
        while(root->right)
            root = root->right;
        
        return root;
    }
    
    TreeNode* helper(TreeNode *root){
        if(!root->right)
            return root->left;
        
        if(!root->left)
            return root->right;
        
        TreeNode* rightChild = root->right;
        TreeNode* smallestRight = solve(root->left);
        
        smallestRight -> right = rightChild;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        if(root->val == key){
            return helper(root);
        }
        
        TreeNode *curr = root;
        
        while(curr){
            if(curr->val > key){
                if(curr->left && curr->left->val == key){
                    curr->left = helper(curr->left);
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right && curr->right->val == key){
                    curr->right = helper(curr->right);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};