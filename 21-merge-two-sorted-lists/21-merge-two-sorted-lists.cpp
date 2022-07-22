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
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        ListNode* dummy = new ListNode();
        ListNode *r = dummy;
        
        if(p ==NULL && q==NULL)
            return p;
        
        else if(p ==NULL)
            return q;
        
        else if(q==NULL)
            return p;
        
        if(p->val <= q->val){
            dummy -> next = p;
            r = p;
            p = p->next;
        }
        else{
            dummy ->next = q;
            r = q;
            q = q->next;
        }
        
        while(p && q)
        {
            if(p->val <=q->val){
                r ->next = p;
                r = p;
                p = p->next;
            }
            else{
                r->next = q;
                r = q;
                q = q->next;
            }
        }
        
        if(p)
            r->next = p;
        else if(q)
            r->next = q;
        return dummy->next;
    }
};