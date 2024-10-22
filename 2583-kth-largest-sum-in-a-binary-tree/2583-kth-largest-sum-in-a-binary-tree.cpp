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
    
//     priority_queue <int, vector<int>, greater<int> > pq;
//     void solve(TreeNode *root, int k){
//         if(root == NULL)
//             return;
        
//         if(pq.size()>k){
//             pq.push(root->val);
//             pq.pop();
//         }
//         else
//             pq.push(root->val);
        
//         solve(root->left,k);
//         solve(root->right,k);
//     }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // solve(root,k);
        
        queue<TreeNode*> que;
        que.push(root);
        // pq.push(root->val);
        vector<long long> v;
        v.push_back(root->val);
        
        while(!que.empty()){
            int n = que.size();
            
            long long sum = 0;
            for(int i = 0; i<n; i++){
                TreeNode *node = que.front();
                que.pop();
                
                if(node->left){
                    sum += node->left->val;
                    que.push(node->left);
                }
                
                if(node->right){
                    sum += node->right->val;
                    que.push(node->right);
                }
            }
            
            if(sum == 0)
                continue;
            
            // cout<<sum<<endl;
            // if(pq.size()>k && pq.top()>sum){
            //     pq.push(root->val);
            //     pq.pop();
            // }
            // else
            //     pq.push(root->val);
            v.push_back(sum);
        }
        
        if(v.size()<k)
            return -1;
        
        sort(v.rbegin(),v.rend());
        
        // for(auto it: v)
        //     cout<<it<<" ";
        
        
        return v[k-1];
    }
};