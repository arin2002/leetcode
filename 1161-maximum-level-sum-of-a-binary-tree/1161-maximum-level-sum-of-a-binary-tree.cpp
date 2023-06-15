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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        int ans = 1, maxSum = root->val;
        
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            
            int temp = 0;
            for(int i = 0; i<n; i++){
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                    // temp+=node->val;
                }
                
                if(node->right){
                    q.push(node->right);
                    // temp+=node->val;
                }
                temp+=node->val;
            }
            
            // level++;
            cout<<temp<<" ";
            if(maxSum<temp){
                ans = level;
                maxSum = temp;
            }
            level++;
        }
        
        return ans;
    }
};