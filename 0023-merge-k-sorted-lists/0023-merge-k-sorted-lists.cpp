
class cmp {
    public:
       bool operator()(ListNode *a, ListNode* b){
           return a->val > b->val;
      }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        
        for(auto it : lists){
            if(it != NULL)
                pq.push(it);
        }
        
        while(pq.size()){
            ListNode *node = pq.top();
            pq.pop();
            
            tail->next = node;
            tail = node;
            if(node->next)
                pq.push(node->next);
        }
        
        return dummy->next;
    }
};