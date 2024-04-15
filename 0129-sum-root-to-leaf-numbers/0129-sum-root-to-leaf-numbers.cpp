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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        
        function<void(TreeNode*,int)> solve = [&](TreeNode* node,int temp){  
            if(node == NULL){
                return;
            }
            
            temp = temp*10 + node->val;
            
            cout<<temp<<" ";
            if(!node->left && !node->right){
                ans += temp;
            }
            
            solve(node->left,temp);
            solve(node->right,temp);
            
        };
        
        solve(root,0);
        return ans;
    }
};