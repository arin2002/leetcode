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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *p = head, *q = head->next, *r = p, *s = q;
        
        while(r && s && s->next){
            r->next = s->next;
            r = r->next;
            s->next = r->next;
            s = s->next;
        }
        r->next = q;
        head = p;
        return head;
    }
};