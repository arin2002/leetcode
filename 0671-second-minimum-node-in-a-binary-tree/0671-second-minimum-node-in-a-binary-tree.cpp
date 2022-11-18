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
    
    void solve(TreeNode *root, set<int> &v){
        if(!root)
            return;
        
        solve(root->left,v);
        v.insert(root->val);
        solve(root->right,v);
    }
    
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> v;
        
        solve(root,v);
        
        if(v.size() < 1)
            return -1;
        
        int i = 2;
        for(auto it : v){
            i--;
            if(i == 0)
                return it;
        }
        
        return -1;
    }
};