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
    
    ListNode* curr;
    Solution(ListNode* head) {
        curr = head;
    }
    
    int getRandom() {
        int res, len = 1;
        ListNode* x = curr;
        while(x){
            if(rand() % len == 0){
                res = x->val;
            }
            len++;
            x = x->next;
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */