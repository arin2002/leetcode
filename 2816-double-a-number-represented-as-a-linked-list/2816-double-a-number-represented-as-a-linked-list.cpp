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
    ListNode* doubleIt(ListNode* head) {
        ListNode *curr = head;
        int carry = 0;
        if (head->val > 4) {
            head = new ListNode(1, head);
        }
        
        while(curr){
            curr->val = (curr->val*2)%10;
            
            if(curr && curr->next){
                int carry = (curr->next->val*2)/10;
                
                if(carry){
                    curr->val++;
                }
            }
            
            curr = curr->next;
        }
        
        return head;
    }
};