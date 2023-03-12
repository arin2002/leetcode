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
    
    ListNode* merge(ListNode *p, ListNode *q){
        ListNode *temp;
        ListNode *dummy = new ListNode();
        temp = dummy;
        
        while(p && q){
            if(p->val <= q->val){
                temp->next = p;
                p = p->next;
            }
            else{
                temp->next = q;
                q = q->next;
            }
            
            temp = temp->next;
        }
        
        if(p) temp->next = p;
        if(q) temp->next = q;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 1)
            return lists[0];
        
        ListNode *root = NULL;
        for(int i = 1; i<n; i++){
            if(root == NULL){
                root = merge(lists[i-1],lists[i]);
            }
            else{
                root = merge(root,lists[i]);
            }
        }
        
        return root;
    }
};