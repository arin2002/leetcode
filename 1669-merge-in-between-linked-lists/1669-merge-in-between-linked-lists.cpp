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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p = list1, *q, *r = list2;
        int c = a;
        
        for(int i = 1; i<a; i++){
            p = p->next;
        }
        
        q = p;
        for(int i = a-1; i<b; i++){
            q = q->next;
        }
        
        while(r->next){
            r = r->next;
        }
        
        cout << p->val<<" "<< q->val;
        p->next = list2;
        r->next = q->next;
        return list1;
    }
};