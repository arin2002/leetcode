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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *q =NULL;
        
        while(p){
            
            if(q !=NULL)
            {
                if(p->val == q->val){
                    q->next = p->next;
                    p = p->next;
                    continue;
                }
            }
            q = p;
            p = p->next;
        }
        
        return head;
    }
};