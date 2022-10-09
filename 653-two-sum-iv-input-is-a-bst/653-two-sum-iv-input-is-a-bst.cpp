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
    vector<int> nums;
    
    void Traverse(TreeNode *root){
        if(!root)
            return;
        
        Traverse(root->left);
        nums.push_back(root->val);
        Traverse(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        Traverse(root);
        
        int i = 0, j = nums.size()-1;
        
        while(i<j){
            int s = nums[i]+nums[j];
            
            if(s==k)
                return true;
            else if(s<k)
                i++;
            else
                j--;
        }
        
        return false;
    }
};