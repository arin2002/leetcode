/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto p = node->next;
        while(p){
            node->val = p->val;
            p = p->next;
            
            if(p == NULL)
                break;
            node = node->next;
        }
        
        node->next = NULL;
    }
};