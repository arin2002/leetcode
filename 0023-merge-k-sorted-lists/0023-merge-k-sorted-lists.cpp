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
    
    
    ListNode* sort(int l, int r,vector<ListNode*>& lists){
        if(l>r)
            return NULL;
        
        if(l == r)
            return lists[r];
                    
        int mid = (l+r)/2;
        ListNode *lower = sort(l,mid,lists);
        ListNode *upper = sort(mid+1,r,lists);
        
        return merge(lower,upper);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        return sort(0,n-1,lists);
    }
};