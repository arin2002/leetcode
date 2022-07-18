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
    
    void helper(TreeNode *root, vector<int> &v)
    {
        if(root == NULL)
            return;
        
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root ==NULL)
            return root;
        
        vector<int>v;
        helper(root,v);
        
        int n = v.size();
        
        TreeNode *head = NULL, *rear = NULL;
        for(int i = 0; i<n; i++)
        {
            TreeNode *temp = new TreeNode(v[i]);
            
            if(head == NULL){
                head = rear = temp;
            }
            else{
                rear->right = temp;
                rear = temp;
            }
        }
        return head;
    }     
};