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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode *p = new TreeNode(val,root->left,NULL);
        
        if(depth == 1){
            p->left = root;
            return p;
        }
        
        
        function<TreeNode* (TreeNode*, int)> solve = [&](TreeNode* root, int d)->TreeNode*{
            if(!root){
                return NULL;
            }
            
            if(d == depth-1){
                TreeNode *p = new TreeNode(val,root->left,NULL);
                TreeNode *q = new TreeNode(val,NULL,root->right);
                root->left = p;
                root->right = q;
                
                return root;
            }
            
            root->left = solve(root->left,d+1);
            root->right = solve(root->right,d+1);
            
            return root;
        };
        
        return solve(root,1);
    }
};