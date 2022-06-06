class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA,*q=headB;
        int n=0,m=0;
        
        while(p){
            n++;
            p=p->next;
        }
        while(q){
            m++;
            q=q->next;
        }
        p=headA;q=headB;
        
        while(p && q)
        {
            if(m<n){
                n--;
                p=p->next;
            }
            else if(n<m)
            {
                m--;
                q=q->next;
            }
            else if(m==n)
            {
                if(p==q)
                    return p;
                p=p->next;
                q=q->next;
            }
        }
        return NULL;
    }
};