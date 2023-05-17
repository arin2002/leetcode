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
    int pairSum(ListNode* head) {
        vector<int> nums;
        
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        
        int i = 0, j = nums.size()-1, ans = 0; 
        while(i<j){
            ans = max(ans,nums[i++]+nums[j--]);
        }
        
        return ans;
    }
};