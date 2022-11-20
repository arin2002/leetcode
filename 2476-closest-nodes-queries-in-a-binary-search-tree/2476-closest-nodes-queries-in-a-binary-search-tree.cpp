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
    
    void solve(TreeNode *root, vector<int> &v){
        if(root == NULL)
            return;
        
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    
    void bs(int k, vector<int> &v, vector<vector<int>> &ans){
        int i = 0, j = v.size()-1;
        
        while(i<=j){
            int mid = i + (j-i)/2;
            
            if(v[mid] == k){
                vector<int> temp;
                temp.push_back(k);
                temp.push_back(k);
                ans.push_back(temp);
                return;
            }
            else if(v[mid] < k)
                i = mid + 1;
            else
                j = mid - 1;
        }
        
        vector<int> temp;
        
        cout<<i;
        if(i == 0){
            temp.push_back(-1);
            temp.push_back(v[i]);
        }
        else if(i == v.size()){
            temp.push_back(v[i-1]);
            temp.push_back(-1);
        }
        else{
            temp.push_back(v[i-1]);
            temp.push_back(v[i]);
        }
        
        ans.push_back(temp);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> v;
        
        solve(root,v);
        
        for(auto it: queries)
            bs(it,v,ans);
        
        return ans;
    }
};