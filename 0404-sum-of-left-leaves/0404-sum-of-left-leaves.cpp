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
    int sumOfLeftLeaves(TreeNode* root) {
        
        function<int(TreeNode*,int)> solve = [&](auto root, int cnt){
            if(!root)
                return 0;
            
            if(cnt == 0){
                if(!root->left && !root->right){
                    return root->val;
                }
            }
            
            return solve(root->left,0) + solve(root->right,1);
        };
        
        return solve(root,-1);
    }
};