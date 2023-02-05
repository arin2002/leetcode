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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        // make it graph
        vector<int> adj[502];
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            
            if(node->right){
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
        
        
        // do bfs now
        queue<int>que;
        que.push(target->val);
        vector<int> vis(502);
        
        int count = 0;
        while(!que.empty()){
            if(count > k)
                break;
            
            int n = que.size();
            for(int i = 0; i<n; i++){
                int node = que.front();
                que.pop();
                vis[node] = 1;
                for(auto it : adj[node]){
                    if(!vis[it])
                        que.push(it);
                }
                
                if(count == k)
                    ans.push_back(node);
            }
            
            count++;
        }
        return ans;
    }
};