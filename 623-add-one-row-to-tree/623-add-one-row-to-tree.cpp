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
    
    void add(TreeNode *root,TreeNode *prev, int f, int val, int k){
        if(root == NULL){
            if(k == 1){
                TreeNode *temp = new TreeNode(val);
                if(f){
                    prev->right = temp;
                }
                else
                    prev->left = temp;
            }
            
            return;
        }
        
        k--;
        cout<<k;
        if(k == 0){
            cout<<1;
            TreeNode *temp = new TreeNode(val);
            if(f == 0){
                temp->left = root;
                prev->left = temp;
            }
            else{
                temp->right = root;
                prev->right = temp;
            }
            return;
        }
        
        add(root->left,root,0,val,k);
        add(root->right,root,1,val,k);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        
        add(root,root,-1,val,depth);
        return root;
    }
};