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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        int n = 0; ListNode *p =head;
        
        if(p==NULL)
            return head;
        
        while(p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        
        sort(v.begin(),v.end());
        p = head;
        
        n = v.size();
        for(int i = 0; i<n; i++)
        {
            head -> val = v[i];
            head = head -> next;
        }
        
        return p;
    }
};