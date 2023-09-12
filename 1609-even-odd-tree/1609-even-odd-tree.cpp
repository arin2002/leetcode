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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            
            int prev = -1;
            for(int i = 0; i<n; i++){
                TreeNode *node = q.front();
                int curr = node->val;
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                
                if(level%2 == 0){
                    if(prev != -1 && curr<=prev || curr%2 == 0)
                        return 0;
                    
                }
                else{
                    if(prev != -1 && curr>=prev || curr%2 != 0)
                        return 0;
                }
                
                prev = curr;
            }
            
            level++;
        }
        
        return 1;
    }
};