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
    
    int ans = INT_MAX;
    
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        
        if(!root->left){
            return 1+solve(root->right);
        }
        else if(!root->right){
            return 1+solve(root->left);
        }
        
        int l = 1+solve(root->left);
        int r = 1+solve(root->right);
        
        cout<<l<<" "<<r<<endl;
        return min(l,r);
    }
    
    int minDepth(TreeNode* root) {
        // return solve(root);
        
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int t = q.front().second;
            q.pop();
            
            if(node->left != NULL){
                q.push({node->left,t+1});
            }
            
            if(node->right != NULL){
                q.push({node->right,t+1});
            }
            
            if(!node->left && !node->right)
                ans = min(ans,t);
        }
        
        return ans;
    }
};