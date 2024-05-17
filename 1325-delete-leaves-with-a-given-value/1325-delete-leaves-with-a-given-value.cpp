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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        function<void(TreeNode*,TreeNode*,int)> solve = [&](TreeNode* curr, TreeNode* prev, int c){
            if(!curr)
                return;
                        
            solve(curr->left,curr,0);
            solve(curr->right,curr,1);
            
            if(curr->val == target && !curr->left && !curr->right){
                if(prev == NULL){
                    root = prev;
                    return;
                }
                
                if(c == 0){
                    prev->left = NULL;
                }
                else{
                    prev->right = NULL;
                }
                
                delete(curr);
                return;
            }
        };
        
        solve(root,NULL,-1);
        return root;
    }
};