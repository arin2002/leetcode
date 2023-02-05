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
    int amountOfTime(TreeNode* root, int start) {
        vector<int> adj[100001];
        
        queue<TreeNode*> que;
        que.push(root);
        
        int count = 0;
        while(!que.empty()){
            TreeNode *node = que.front();
            int v = node->val;
            que.pop();
            
            count = max(count,v);
            
            if(node->left){
                int u = node->left->val;
                adj[u].push_back(v);
                adj[v].push_back(u);
                que.push(node->left);
            }
            
            if(node->right){
                int u = node->right->val;
                adj[u].push_back(v);
                adj[v].push_back(u);
                que.push(node->right);
            }
            
        }
        
        vector<int> vis(count+1);
        count = 0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i = 0; i<n; i++){
                int node = q.front();
                q.pop();
                vis[node] = 1;
                
                for(auto it : adj[node]){
                    if(!vis[it])
                        q.push(it);
                }
            }
            count++;
        }
        return count-1;
    }
};