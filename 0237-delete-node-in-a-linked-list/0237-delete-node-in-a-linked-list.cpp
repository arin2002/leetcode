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
    void deleteNode(ListNode* node) {
        // pointer to next node
        ListNode* nextNode = node->next;
        // copy that value
        node->val = nextNode->val;
        // link them
        node->next = nextNode->next;
        // delete next node
        delete(nextNode);
    }
};