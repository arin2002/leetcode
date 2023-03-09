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
        ListNode *fast = head, *slow = head;
        
        if(head == NULL)
            return head;
        
        if(head && head->next == NULL)
            return NULL;
        
        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(fast!=slow && fast && fast->next);
        
        // cout<<fast->val;
        if(fast == NULL || fast->next == NULL)
            return NULL;
        
        slow = head;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
            
    }
};