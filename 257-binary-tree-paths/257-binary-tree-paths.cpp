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
    vector<string> s;

    void helper(TreeNode *r,string st){
        
        if(r == NULL)
            return;
        
        if(r && !r->left && !r->right){
            s.push_back(st);
            return;
        }
        
        
        if(r->left) helper(r->left, st+"->"+ to_string(r->left->val));
        if(r->right) helper(r->right, st+"->"+ to_string(r->right->val));
            
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return s;
        
        helper(root,to_string(root->val));
        
        return s;
    }
};