class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "~";
        int num;
        
        function<void(TreeNode*,string)>solve = [&](auto root, string t){
            if(!root){
                return;
            }
            
            // this is not good instead reverse is work
            // t = (char)(root->val+'a') + t;
            t += (char)(root->val+'a');
            
            if(!root->left && !root->right){
                reverse(t.begin(),t.end());
                ans = min(ans,t);
            }
            
            solve(root->left,t);
            solve(root->right,t);
        };
        
        
        solve(root,"");
        return ans;
    }
};