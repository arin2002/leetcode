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
        ListNode* prev = NULL, *curr = head, *next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead, *p, *prev;
        int carry = 0;
        
        newHead = reverse(head);
        p = newHead;
        
        while(p || carry){
            int a = 0;
            
            if(p)
                a = p->val;
            
            
            int prod = (a*2+carry)%10;
            carry = (a*2+carry)/10;
            
            if(p){
                p->val = prod;
                prev = p;
                p = p->next;
            }
            else{
                ListNode *temp = new ListNode(prod);
                prev->next = temp;
                prev = temp;
            }
        }
        
        return reverse(newHead);
    }
};