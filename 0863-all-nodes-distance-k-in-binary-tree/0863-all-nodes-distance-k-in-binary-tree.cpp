/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> ump;
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                ump[node->val].push_back(node->left->val); 
                ump[node->left->val].push_back(node->val); 
                q.push(node->left);
            }
            
            if(node->right){
                ump[node->val].push_back(node->right->val);
                ump[node->right->val].push_back(node->val); 
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        bfs(root);
        vector<int> vis(501);
        queue<pair<int,int>> q;
        vector<int> ans;
        
        q.push({target->val,0});
        
        while(!q.empty()){
            int node = q.front().first;
            int temp = q.front().second;
            vis[node] = 1;
            q.pop();
            cout<<temp<<" ";
            if(temp>k)
                break;
            if(temp == k){
                ans.push_back(node);
            }
            
            for(auto &it: ump[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,temp+1});
                }
            }
            
        }
        
        return ans;
    }
};