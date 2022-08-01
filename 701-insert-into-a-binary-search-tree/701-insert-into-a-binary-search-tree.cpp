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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *p = root, *q = NULL;
        TreeNode *temp = new TreeNode(val);
        if(root == NULL){
            root = temp;
            return root;
        }
        
        while(p)
        {
            q = p;
            if(p->val > val)
                p = p->left;
            else
                p = p->right;
        }
        
        if(q->val > val){
            q->left = temp;
        }
        else
            q->right = temp;
        
        return root;
    }
};