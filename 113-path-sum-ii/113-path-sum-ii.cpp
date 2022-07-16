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
    vector<vector<int>> ans;
    vector<int> temp;
    
    
    void helper(TreeNode *root, int sum)
    {
        if(!root)
        {
            // if(sum==0)
            //     ans.push_back(temp);
            return;
        }
        if(root->left == NULL && root->right == NULL)
        { 
            if(sum - root->val == 0)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        }
        


            temp.push_back(root->val);
            sum -= root->val;
            helper(root->left,sum);
            helper(root->right,sum);
            temp.pop_back();
        //sum += root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return ans;
        
        helper(root,targetSum);
        return ans;
    }
};