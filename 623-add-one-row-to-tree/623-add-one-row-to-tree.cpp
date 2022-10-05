class Solution {
    void addNode(TreeNode * root,TreeNode * par, int val , int depth, int child){
        if(depth<1)return;
        if(depth == 1){
            TreeNode * n = new TreeNode(val);
            if(child){
                n->right = par->right;
                par->right = n;
            }
            else{
                n->left = par->left;
                par->left = n;
            }
            return;
        }
        else{
            if(root)addNode(root->left,root,val,depth-1,0);
            if(root)addNode(root->right,root,val,depth-1,1);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * n = new TreeNode(val);
            n->left = root;
            return n;
        }
        addNode(root,root,val,depth,0);
        return root;
    }
};
