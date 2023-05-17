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
    int pairSum(ListNode* head) {
        ListNode* fast = head, *slow = head;
        int ans = 0;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // slow is pointing at middle
        // cout<<slow->val<<" ";
        
        // now apply reverse concept of linked list
        ListNode *prev = NULL, *next = slow->next, *curr = slow;
        
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        
        curr->next = prev;
        
        fast = curr;
        while(fast){
            cout<<fast->val<<" ";
            fast = fast->next;
        }
        
        while(curr){
            ans= max(ans,head->val+curr->val);
            head = head->next; curr = curr->next;
        }
        return ans;
    }
};