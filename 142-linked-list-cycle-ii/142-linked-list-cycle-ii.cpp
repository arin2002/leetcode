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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *p =head, *q = head;
        
        if (head == NULL || head->next == NULL)
        return NULL;

        while(p && p->next)
        {
            q = q->next;
            p = p->next->next;
            
            if(p==q){
                break;
            }
        }
        
        if (p != q)
        return NULL;

        q = head;
        
        while(p!=q)
        {
            q = q->next;
            p = p->next;
            
            if(p==q)
                return p;
        }
        return p;
    }
};