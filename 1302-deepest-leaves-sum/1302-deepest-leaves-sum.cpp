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
    
    int sum = 0;
    int deep = 0;
    
    int helper(TreeNode *root, int h)
    {
        if(root == NULL)
            return  0;
        
        if(!root->left && !root->right)
        {
            if(h == deep)
                sum+= root->val;
            else if(h > deep){
                sum = root->val;
                deep = h;
            }
        }
        
        helper(root->left,h+1);
        helper(root->right,h+1);
        
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        return helper(root,1);
    }
};