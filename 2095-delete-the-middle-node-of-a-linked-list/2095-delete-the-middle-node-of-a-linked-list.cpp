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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p = head, *q = head;
        
        vector<int> v;      
        while(p){
            v.push_back(p->val);
            p = p->next;
        }
        
        int n = v.size();
        v[n/2] = 0;
        
        p = head;
        
        if(n==1)
            return NULL;
        
        for(auto i: v){
            if(i == 0)
                continue;
            q = p;
            p->val = i;
            p = p->next;
        }
        q->next = NULL;
        return head;
    }
};