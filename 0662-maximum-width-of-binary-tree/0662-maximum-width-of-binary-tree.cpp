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
    int widthOfBinaryTree(TreeNode* root) {
        // level order with index
        // i index of parent -> child ke 2i+1, 2i+2
        // for solving overflow uss ke index ko min se subtract karo
        queue<pair<TreeNode*,int>> que;
        que.push({root,0});
        
        int ans = 0;
        while(!que.empty()){          
            int n = que.size();
            int mini = que.front().second, temp1,temp2;
            
            for(int i = 0; i<n; i++){
                TreeNode* node = que.front().first;  
                long long y = que.front().second - mini;
                que.pop();
                
                if( i == 0)
                    temp1 = y;
                
                if(i == n-1)
                    temp2 = y;
                
                if(node->left)
                    que.push({node->left,2*y+1});
                
                if(node->right)
                    que.push({node->right,2*y+2});
            }
            
            ans = max(ans,(temp2-temp1+1));
        }
        
        return ans;
    }
};