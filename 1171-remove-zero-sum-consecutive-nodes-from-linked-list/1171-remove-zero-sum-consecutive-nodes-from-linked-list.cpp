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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* p = dummy;
        
        while(p){
            ListNode*q = p->next;
            int sum = 0;
            
            while(q){
                sum += q->val;
                q = q->next;
                
                if(sum == 0){
                    p->next = q;
                }
            }
            
            p = p->next;
            q = p;
        }
        
        return dummy->next;
    }
};