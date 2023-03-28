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
    
    TreeNode* solve(int preSt, int preEnd, int &postInd, vector<int>& inorder, vector<int>& postorder){
        if(preEnd < preSt)
            return NULL;
        
        TreeNode *node = new TreeNode(postorder[postInd--]);
        int ind = find(inorder.begin(),inorder.end(),node->val)-inorder.begin();
        
        node->right = solve(ind+1,preEnd,postInd,inorder,postorder);
        node->left = solve(preSt,ind-1,postInd,inorder,postorder);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size()-1;
        return solve(0,n,n,inorder,postorder);
    }
};