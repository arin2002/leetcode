/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        unordered_map<Node*, Node*> mp;
        for(auto *ptr = head; ptr; ptr = ptr->next) {
            mp[ptr] = new Node(ptr->val);
        }
        for(auto *ptr = head; ptr; ptr = ptr->next) {
            mp[ptr]->next = ptr->next ? mp[ptr->next] : nullptr;
            mp[ptr]->random = ptr->random ? mp[ptr->random] : nullptr;
        }
        return mp[head];
    }
};