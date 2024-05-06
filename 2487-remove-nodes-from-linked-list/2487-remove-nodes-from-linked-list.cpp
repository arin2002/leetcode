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
        if(head == NULL)
            return head;
            
        ListNode* prev = NULL, *curr = head, *next = head->next;
        
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        
        curr->next = prev;
        return curr;
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead, *curr, *start;
        
        newHead = reverse(head);
        curr = newHead->next; start = newHead;
        
        while(curr){
            int a = start->val;
            
            while(curr && a>curr->val){
                curr = curr->next;
            }
            
            start->next = curr;
            start = curr;
            
            if(!curr)
                break;
            
            curr = curr->next;
        }
        
        
        return reverse(newHead);
    }
};