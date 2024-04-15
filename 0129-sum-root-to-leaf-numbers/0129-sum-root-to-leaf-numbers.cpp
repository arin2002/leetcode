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
        
        function<int(TreeNode*,int)> solve = [&](TreeNode* node,int temp){  
            if(node == NULL){
                return 0;
            }
            
            temp = temp*10 + node->val;
            
            cout<<temp<<" ";
            if(!node->left && !node->right){
                return temp;
            }
            
            return solve(node->left,temp)+solve(node->right,temp);
        };
        
        return solve(root,0);
    }
};