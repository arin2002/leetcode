class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p = head, *r = head;

        vector<int> v;

        int sum = 0;
        p = p->next;
        while(p){
            if(p->val == 0){
                r->val = sum;
                if(p->next)
                    r = r->next;
                sum = 0;
            }
            sum += p->val;
            p = p->next;
        }

        r->next = NULL;
        return head;
    }
};