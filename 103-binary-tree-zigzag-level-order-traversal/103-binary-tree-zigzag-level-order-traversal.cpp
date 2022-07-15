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
        
        bool flag = true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i<n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                int index = flag ? i : n-1-i;
                if(node->left) q.push(node->left);
                if(node->right)  q.push(node->right);
                
                temp[index] = node->val;
            }
            flag = !flag;
            // if(k%2 !=0)
            //     reverse(temp.begin(),temp.end());
            // k++;
            ans.push_back(temp);
        }
        return ans;
    }
};