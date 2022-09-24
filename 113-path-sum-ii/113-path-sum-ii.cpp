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
    vector<vector<int>> ans;
    
    void f(TreeNode *root, int k, vector<int> temp){
        if(!root)
            return;
        
        temp.push_back(root->val);
        k-=root->val;
        if(root->left == NULL && root->right == NULL && k == 0){
            ans.push_back(temp);
            return;
        }
        
        f(root->left,k,temp);
        f(root->right,k,temp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        f(root,targetSum,temp);
        
        return ans;
    }
};