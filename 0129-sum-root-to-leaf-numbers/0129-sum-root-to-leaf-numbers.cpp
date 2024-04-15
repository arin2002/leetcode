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
        
        function<void(TreeNode*,string)> solve = [&](TreeNode* node,string s){  
            if(node == NULL){
                return;
            }
            
            if(!node->left && !node->right){
                s += to_string(node->val);
                ans += stoi(s);
                s.pop_back();
                return;
            }
            
            solve(node->left,s+to_string(node->val));
            solve(node->right,s+to_string(node->val));
            
        };
        
        solve(root,"");
        return ans;
    }
};