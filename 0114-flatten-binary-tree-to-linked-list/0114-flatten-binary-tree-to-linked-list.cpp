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
    vector<int> ans;
    
    void preorder(TreeNode* root){
        if(!root)
            return;
        
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        preorder(root);
        TreeNode * prev = root, *curr = root;
        for(auto it : ans){
            if(curr){
                if(curr->left)
                    curr->left = NULL;
                
                curr->val = it;
                prev = curr;
                curr = curr->right;
            }
            else{
                TreeNode *node = new TreeNode(it);
                
                prev->right = node;
                prev = node;
                curr = node->right;
            }   
        }
    }
};