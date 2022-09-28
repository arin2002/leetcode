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
        ListNode *p = head;
        
        vector<int> v;
        while(p){
            v.push_back(p->val);
            p = p->next;
        }
        
        int n = v.size();
        swap(v[k-1],v[n-k]);
        
        p = head;
        for(int i = 0; i<n; i++){
            p->val = v[i];
            p = p->next;
        }
        
        return head;
    }
};