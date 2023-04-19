class Solution {
public:
    int longestZigZag(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        if(!root)
            return 0;
        
        if(root->left){
            q.push({root->left,{0,1}});
        }
        
        if(root->right){
            q.push({root->right,{1,1}});
        }
        
        int ans = 0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int temp = q.front().second.second;
            ans = max(ans,temp);
            int flag = q.front().second.first;
            q.pop();
            
            if(node->left){
                if(flag == 0){
                    q.push({node->left,{0,1}});
                }
                else{
                    q.push({node->left,{0,temp+1}});
                }
            }
            
            if(node->right){
                if(flag == 0){
                    q.push({node->right,{1,temp+1}});
                }
                else{
                    q.push({node->right,{1,1}});
                }
            }

        }
        
        return ans;
    }
};