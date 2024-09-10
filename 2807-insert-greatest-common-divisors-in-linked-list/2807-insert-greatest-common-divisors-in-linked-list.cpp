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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p = head, *q = head->next;
        
        while(p&&q){
            ListNode *temp = new ListNode(__gcd(p->val,q->val));
            p->next = temp;
            temp->next = q;
            p = q;
            q = q->next;
        }
        
        return head;
    }
};