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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* fast = head->next, *slow = head;
        ListNode* newHead = fast, *tail = head;
        
        while(fast){
            ListNode *temp = fast;
            fast = fast->next;
            
            temp->next = slow;
            slow->next = NULL;
            if(temp != head)
                tail->next = temp;
            
            tail = slow;
            
            slow = fast;
            if(fast)
            fast =fast->next;
        }
        
        if(slow){
            tail->next = slow;
            tail = slow;
        }
        
        tail->next = NULL;
        
        // cout<<tail->val;
        // cout<<1;
        
        // while(newHead){
        //     cout<<newHead->val << " ";
        //     newHead = newHead->next;
        // }
        return newHead;
    }
};