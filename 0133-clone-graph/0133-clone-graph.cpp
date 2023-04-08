/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    
    // 1st wala apna origanl denote kar raha
    // 2nd wala new node jo banyi h vo ha
    // dry run must ha
    unordered_map<Node*,Node*> ump;
    
    Node* dfs(Node* node){
        Node* root = new Node(node->val);
        ump[node] = root;
        
        for(auto it: node->neighbors){
            if(ump.find(it) != ump.end()){
                root->neighbors.push_back(ump[it]);
            }
            else{
                dfs(it);
                //backtrack step
                root->neighbors.push_back(ump[it]);
            }
        }
        
        return root;
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return node;
        
        int n = node->neighbors.size();
        
        if(n == 0){
            return new Node(node->val);
        }
        
        return dfs(node);
    }
};



