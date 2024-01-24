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
    
    void f(TreeNode * root, vector<int> v, int &count, int h){
        
        v[root->val]++;
        if(root->left == NULL && root->right ==NULL){
            if(h%2){
                int c = 0;
                for(int i = 1; i<10; i++){
                    if(v[i] % 2 == 1)
                        c++;
                    
                }
                if(c == 1)
                    count++;
                    
            }
            else{
                int flag  = 0;
                for(int  i = 1; i<10; i++){
                    if(v[i] %2 == 1){
                        flag = 1;
                        break;
                    }
                }
                
                if(flag == 0)
                    count++;
            }
            
            return;
        }
        
        if(root->left)
            f(root->left,v,count,h+1);
        
        if(root->right)
        f(root->right,v,count,h+1);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        int count = 0;
        f(root,v,count,1);
        
        return count;
    }
};