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
    
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL, *next = head;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode * fast = head, *slow = head;
        
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }        
        
        ListNode * p = reverse(slow->next), *q = head->next, *r, *s, *t = p, *prev1 = NULL, *prev2 = NULL;
        slow->next = NULL;
        
        while(p && q){
            r = p->next;
            p->next = q;
            prev1 = p;
            p = r;
            
            s = q->next;
            q->next = p;
            prev2 = q;
            q = s;
        }
        
        if(p){
            prev1->next = p;
        }
        
        if(q){
            prev2->next = q;
        }
        
        head->next = t;
    }
};







