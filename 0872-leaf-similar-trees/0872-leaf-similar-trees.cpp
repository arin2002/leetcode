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
    
    void solve(TreeNode* root, vector<int> &arr){
        if(root == NULL)
                return;
        
        if(root->left == NULL && root->right == NULL){
                arr.push_back(root->val);
            }
            
            solve(root->left,arr);
            solve(root->right,arr);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> a, b;
        solve(root1,a);
        solve(root2,b);
        
        
        int n = a.size(), m = b.size();
        if(n != m)
            return false;
        
        for(int i = 0; i<n; i++){
            if(a[i] != b[i])
                return false;
        }
        
        return true;
    }
};