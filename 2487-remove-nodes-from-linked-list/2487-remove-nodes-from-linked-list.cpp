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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> st;
        
        while(curr){
            while(!st.empty() && st.top()->val < curr->val){
                st.pop();
            }
            
            if(st.empty()){
                head = curr;
            }
            else{
                auto p = st.top();
                p->next = curr;
            }
            
            st.push(curr);
            curr = curr->next;
        }
        
        if(st.empty())
            return NULL;
        
        return head;
    }
};