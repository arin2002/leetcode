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
    
    int count = 0;
    
    
    void path(TreeNode *root, long long k){
        if(!root)
            return;
        
        k-=root->val;
        
        if(k == 0)
            count++;
        
        path(root->left,k);
        path(root->right,k);
    }
    
    
    void trav(TreeNode *root, int k){
        if(!root)
            return;
    
        path(root,k);
        trav(root->left,k);
        trav(root->right,k);
        
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        trav(root,targetSum);
        
        return count;
    }
};