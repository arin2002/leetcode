class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL)return head;


        ListNode*node=new ListNode(0);//Placing all lower in list
        ListNode*high=new ListNode(0);//placing all higher in list
        ListNode*mark1=node;
        ListNode*mark2=high;

        while(head!=NULL){
            if(head->val<x){
                node->next=new ListNode(head->val);
                node=node->next;
            }
            else{
                high->next=new ListNode(head->val);
                high=high->next;
            }
            head=head->next;
        }
        node->next=mark2->next;//merging two list lower than higher.
        return mark1->next;
    }
};
