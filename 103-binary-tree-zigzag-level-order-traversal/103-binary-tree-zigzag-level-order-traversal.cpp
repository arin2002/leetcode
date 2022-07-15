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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        int k = 0;
        while(!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i<n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                temp.push_back(node->val);
            }
            
            if(k%2 !=0)
                reverse(temp.begin(),temp.end());
            k++;
            ans.push_back(temp);
        }
        return ans;
    }
};