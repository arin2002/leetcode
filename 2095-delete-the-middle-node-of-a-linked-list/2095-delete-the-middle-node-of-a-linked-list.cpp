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
    ListNode* deleteMiddle(ListNode* head) {
                if(head->next == NULL)
            return NULL;
        
        ListNode* p = head->next->next, *q = head;
        while(p && p->next){
            p = p->next->next;
            q = q->next;
        }
        
        cout<<q->val;
        q->next = q->next->next;
        return head;
    }
};