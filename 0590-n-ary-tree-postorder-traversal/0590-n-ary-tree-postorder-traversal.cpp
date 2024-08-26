/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        
        function<void(Node*)> solve = [&](Node* node){
            if(root == NULL){
                return;
            }
            
            for(Node* &child : node->children){
                solve(child);
            }
            
            ans.push_back(node->val);
        };
        
        solve(root);
        return ans;
    }
};