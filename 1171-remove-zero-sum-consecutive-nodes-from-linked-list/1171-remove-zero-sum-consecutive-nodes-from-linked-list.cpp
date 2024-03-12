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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode* p = head, *q = head, *prev = p;
        
        while(p){
            int sum = 0;
            while(q){
                sum += q->val;
                q = q->next;
                
                if(sum == 0){
                    if(p == head)
                        head = q;
                    else{
                        prev->next = q;
                    }
                    break;
                }
            }
            
            cout<<sum<<endl;
            if(sum == 0){
                q = head;
                p = head;
            }
            else{
                prev = p;
                p = p->next;
                q = p;
            }
        }
        
        return head;
    }
};