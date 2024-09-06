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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        
        ListNode *t = new ListNode(-1,head);
        ListNode *prev = t;
        ListNode *p = t->next;
        
        while(p){
            if(st.find(p->val) != st.end()){
                prev->next = p->next;
            }
            else{
                prev = p;
            }
            
            p = p->next;
        }
        
        return t->next;
    }
};