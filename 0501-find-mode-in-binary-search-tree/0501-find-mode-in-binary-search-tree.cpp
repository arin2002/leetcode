class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxcnt = 0, cnt = 0;
        int prev = -1; // Initialize prev to a value that won't be encountered in the tree
        
        function<void(TreeNode*)> solve = [&](TreeNode* root){
            if(!root){
                return;
            }
            
            solve(root->left);
            int curr = root->val;
            
            if(curr == prev){
                cnt++;
            }
            else{
                cnt = 1; // Reset cnt for a new value
            }
            
            if(cnt >= maxcnt){
                if(cnt > maxcnt){
                    ans.clear(); // Clear ans when we find a new maximum frequency
                    maxcnt = cnt;
                }
                ans.push_back(curr);
            }
            
            prev = curr; // Update prev for the next iteration
            solve(root->right);
        };
        
        solve(root);
        return ans;
    }
};