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
    
    
    
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        queue<Node*> q;
        
        q.push(root);
        
        if(root == NULL)
            return v;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            
            for(int i = 0; i<n; i++){
                Node* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                
                for(auto i : cur->children){
                    q.push(i);
                }
            }
            v.push_back(temp);
        }
        
        return v;
    }
};