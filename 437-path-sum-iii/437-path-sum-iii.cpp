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
    
    int count = 0;
    unordered_map<long,int> ump;
    
    
    
    void f(TreeNode * root, long long runSum, int k){
        if(!root)
            return;
        
        runSum += root->val;
        
        if(runSum == k)
            count++;
        
        if(ump.find(runSum-k) != ump.end()){
            count += ump[runSum - k];
        }
        
        ump[runSum]++;
        f(root->left,runSum,k);
        f(root->right,runSum,k);
        
        ump[runSum]--;
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        
        f(root,0,targetSum);
        return count;
    }
};