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
        if(!head->next)
            return head;
        
        ListNode* prev = head, *curr = head->next;
        
        while(curr){
            int num = __gcd(prev->val,curr->val);
            ListNode *node = new ListNode(num);
            prev->next = node;
            node->next = curr;
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};