/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *p = head, *q = head, *r = NULL;
        
        if(head->next == NULL)
            return NULL;
        
        while(p && p->next){
            p = p->next->next;
            r = q;
            q = q->next;
        }
        
        if(q->next == NULL)
            r->next = NULL;
        
        
        r->next = q->next;
        return head;
    }
};