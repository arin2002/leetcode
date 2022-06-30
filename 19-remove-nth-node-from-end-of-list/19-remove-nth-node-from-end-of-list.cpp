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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head,*q=NULL,*r=NULL;
        int size=0,i=0;
        while(p!=NULL)
        {
            r=q;
            q=p;
            size++;
            p=p->next;
        }
        int a=size-n+1;
        
        if(a==1)
            head=head->next;
        
        else if(a==size)
            r->next=NULL;
        
        else
        {
            p=head;
            q=NULL;
            r=NULL;
            while(p!=NULL && i!=a)
            {
                r=q;
                q=p;
                i++;
                p=p->next;
            }
            r->next=p;
        }
        return head;
    }
};