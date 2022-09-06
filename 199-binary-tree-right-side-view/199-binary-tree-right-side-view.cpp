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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        
        if(!root)
            return v;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int n = que.size();
            
            for(int i = 0; i<n; i++){
                TreeNode *r = que.front();
                que.pop();
                if(i==0)
                v.push_back(r->val);
                
                if(r->right) que.push(r->right);
                if(r->left) que.push(r->left);
            }
        }
        
        return v;
    }
};