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
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        int num;
        
        function<void(TreeNode*,string)>solve = [&](auto root, string t){
            if(!root){
                return;
            }
            
            t = (char)(root->val+'a') + t;
            
            if(!root->left && !root->right){
                if(ans.size() == 0){
                    ans = t;
                }
                else if(ans > t){
                    ans = t;
                }
            }
            
            solve(root->left,t);
            solve(root->right,t);
        };
        
        
        solve(root,"");
        
//         cout<<num;
//         while(num){
//             ans.push_back((char)(num%10+'a'));
//             num /= 10;
//         }
        
//         reverse(ans.begin(),ans.end());
        return ans;
    }
};