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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> a={-1,-1};
        if(head==NULL||head->next==NULL) return a;
      
       ListNode* prev=head;
       head=head->next;
       int d=1,first=-1,last=INT_MIN;
       int mn=INT_MAX;
       while(head->next!=NULL)
       {
        if((long)(head->val - prev->val)*(head->val -head->next->val)>0)
        {
            
            if(first==-1) first =d;
            else mn=min(mn,d-last);
            last=d;
            
            
        }
         prev=head;
         head=head->next;
         d++;
       }
        if(first==last||first==-1) return a;
        a[0]=mn;a[1]=last-first;
        return   a;
    }
};