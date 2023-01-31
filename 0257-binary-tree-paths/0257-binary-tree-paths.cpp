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
    vector<string> ans;
    
    void solve(TreeNode *root, string temp){
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }
        
        temp += to_string(root->val)+"->";
        solve(root->left,temp);
        solve(root->right,temp);
        temp.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};