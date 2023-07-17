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
    
    ListNode* reverse(ListNode* head){
        ListNode *curr  = head, *next = head->next, *prev = NULL;
        
        while(curr && next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        int c = 0;
        
        while(l1 || l2 || c){
            int a = 0, b = 0;
            if(l1){
                a = l1->val;
                l1= l1->next;
            }
            
            if(l2){
                b = l2 ->val;
                l2 = l2->next;
            }
            
            int sum = (a+b+c);
            c = sum/10;
            
            // if(l1){
            //     l1->val = sum;
            //     curr->next = l1;
            // }
            // else if(l2){
            //     l2->val = sum;
            //     curr->next = l2;
            // }
            // else{
            //     ListNode *node = new ListNode();
            //     node->val = sum;
            //     curr->next = node;
            // }
            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;
        }
        ans = reverse(ans->next);
        return ans;
    }
};