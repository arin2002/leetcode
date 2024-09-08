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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        vector<int> nums;
        ListNode *p = head;
        
        while(p){
            nums.push_back(p->val);
            p = p->next;
        }
        
        int total = nums.size(), ind  = 0;
        p = head;
        
        while(p){
            int n = ceil(total/(double)k);
            total -= n;
            k--;
            
            ans[ind++] = p;
            for(int i = 0; i<n-1; i++){
                p = p->next;
            }
            
            ListNode *q = p;
            p = p->next;
            q->next = NULL;
        }
        
        return ans;
    }
};