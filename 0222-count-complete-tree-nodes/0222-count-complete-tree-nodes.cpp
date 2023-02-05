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
    
    int findL(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        
        return count;
    }
    
    int findR(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        
        return count;
    }
    
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int l = findL(root);
        int r = findR(root);
        
        // 2^h-1 nodes if there is full binary tree with all nodes
        // tc will log n whole square
        if(l == r){
            return (1<<l)-1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};