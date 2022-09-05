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
    void invert(TreeNode*& rootl,TreeNode*&rootr)
    {
        if(rootl==NULL&&rootr==NULL)
            return;
        else if(rootl==NULL&&rootr!=NULL)
        {
            rootl=rootr;
            rootr=NULL;
            invert(rootl->left,rootl->right);
            return;
    
        }
        else if(rootl!=NULL&&rootr==NULL)
        {
            rootr=rootl;
            rootl=NULL;
             invert(rootr->left,rootr->right);
            return;
        }
        else
        {
            TreeNode*temp=rootl;
            rootl=rootr;
            rootr=temp;
            
        }
        invert(rootl->left,rootl->right);
        invert(rootr->left,rootr->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        
        invert(root->left,root->right);
        return root;
    }
};