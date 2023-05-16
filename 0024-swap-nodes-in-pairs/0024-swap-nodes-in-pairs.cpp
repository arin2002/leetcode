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
        ListNode* dummy = new ListNode();
        
        ListNode *p = head;
        dummy->next = head;
        ListNode *prev = dummy;
        
        while(p && p->next){
            ListNode *first = p;
            ListNode *second = p->next;
            
            //swap and attach
            prev->next = second;
            // rest jitna baccha h jod do first se
            first->next = second->next;
            //reverse
            second->next = first;
            
            //attach
            prev = first;
            p = first->next;
        }
        
        return dummy->next;
    }
};