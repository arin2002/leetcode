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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        
        while(curr && curr->next){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        head = curr;
        
        ListNode * p = curr, *q = NULL;
        while(n!=1){
            q = p;
            p = p->next;
            n--;
        }
        
        if(q==NULL){
            head = head->next;
        }
        else if(p->next == NULL){
            q->next = NULL;
        }
        else{
            q->next = p->next;
        }
        
        if(head == NULL)
            return head;
        
        curr = head; prev = NULL; next = NULL;
        while(curr && curr->next){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        head = curr;
        return head;
    }
};