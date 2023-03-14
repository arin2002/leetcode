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
    
    void traverse(TreeNode *root, string temp){
        if(!root)
            return;
        
        if(root->left == NULL && root->right == NULL){
            temp += to_string(root->val);
            ans += stoi(temp);
            return;
        }
        
        temp += to_string(root->val);
        traverse(root->left,temp);
        traverse(root->right,temp);
    }
    
    
    int sumNumbers(TreeNode* root) {
        traverse(root,"");
        return ans;
    }
};