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
        ListNode *curr = head, *prev = NULL;
        int carry = 0;
        
        while(curr){
            int prod = (curr->val*2+carry)%10;
            carry = (curr->val*2+carry)/10;
            
            curr->val = prod;
            
            if(carry){
                if(prev == NULL){
                    ListNode* temp = new ListNode(1,curr);
                    head = temp;
                }
                else
                    prev->val = prev->val+1;
            }
            
            carry = 0;
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};