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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = NULL, *q = NULL, *r = head;
        ListNode *head1 = NULL, *head2 = NULL;
        
        if(head == NULL)
            return head;
        
        while(r){
            int val = r->val;
            
            if(val < x){
                if(p == NULL){
                    p = r;
                    head1 = p;
                }
                else{
                    p->next = r;
                    p = r;
                }
        
            }
            else{
                if(q == NULL){
                    q = r;
                    head2 = q;
                }
                else{
                    q->next = r;
                    q = r;
                }
            }
            r = r->next;
        }
        
        if(head1 == NULL){
            q->next = NULL;
            return head2;
        }
        
        if(head2 == NULL){
            p->next = NULL;
            return head1;
        }
        
        p->next = head2;
        q->next = NULL;    
        return head1;
    }
};