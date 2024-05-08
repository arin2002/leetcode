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
    ListNode* partition(ListNode* head, int x) {
        // ListNode *p = NULL, *q = NULL, *r = head;
        // ListNode *head1 = NULL, *head2 = NULL;
        
        ListNode *left = new ListNode();
        ListNode *right = new ListNode();
        
        ListNode *p = left, *q = right, *r = head;
        
        while(r){
            int val = r->val;
            
            if(val < x){
                p = p->next = r;
            }
            else{
                q = q->next = r;
            }
            
            r = r->next;
        }
        
        
        p->next = right->next;
        q->next = NULL;
        
        auto ans = left->next;
        
        
        // memory leak
        delete left;
        delete right;

        return ans;
    }
};