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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head, *q = head, *r = head;
        
        int cnt = 0;
        while(r != NULL){
            cnt++;
            if(cnt == k){
                p = r;
            }
            r = r->next;
        }
        
        int fromfront = cnt-k+1;
        // cout<<fromfront;
        r = head;
        cnt = 0;
        while(r!= NULL){
            cnt++;
            if(cnt == fromfront){
                q = r;
                break;
            }
            r = r->next;
        }
        
        cout<<p->val<<" "<<q->val;
        swap(p->val,q->val);
        return head;
    }
};