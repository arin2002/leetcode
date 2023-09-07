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
    ListNode* reverse(ListNode* head, int i, int r){
        ListNode* curr = head, *prev = NULL,  *next = head->next;
        
        while(next && i!=r-1){
            curr->next = prev;
            prev = curr;
            curr = next;
            
            if(next)
                next = next->next;
            i++;
        }
        curr->next = prev;
        head->next = next;
        return curr;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *p = head, *q = NULL;
        int i = 0;
        for(; i<left-1; i++){
            q = p;
            p = p->next;
        }
        
        ListNode* ans = reverse(p,i,right);
        // return ans;
        if(q == NULL){
            return ans;
        }
        
        q->next = ans;
        return head;
    }
};