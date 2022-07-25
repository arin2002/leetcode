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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        if(head->val == val)
            head = head->next;
        
        ListNode *p = head, *q = NULL;
        
        while(p)
        {
            if(p->val == val)
            {
                if(q==NULL){
                    head = head->next;
                    p = p->next;
                    continue;
                }
                q->next = p->next;
                p = p->next;
                continue;
            }
            
            
            q = p;
            p = p->next;
        }
        
        return head;
    }
};