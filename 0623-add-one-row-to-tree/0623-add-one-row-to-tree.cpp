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
        
        int d = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            if(d == depth)
                break;
            
            for(int i = 0; i<n; i++){
                auto node = q.front();
                q.pop();
                
                if(d == depth-1){
                    TreeNode *p = new TreeNode(val,node->left,NULL);
                    TreeNode *q = new TreeNode(val,NULL,node->right);
                    
                    node->left = p;
                    node->right = q;
                }
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right){
                    q.push(node->right);
                }
            }
            
            d++;
        }
        
        return root;
    }
};