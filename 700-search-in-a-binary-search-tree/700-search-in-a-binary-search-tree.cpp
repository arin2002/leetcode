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
    
    TreeNode* ans = NULL;
    
    void search(TreeNode* root,int v)
    {
        if(root ==  NULL)
            return;
        if(root->val == v){
            ans = root;
            return;
        }
        search(root->left,v);
        search(root->right,v);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        search(root,val);
        return ans;
    }
};