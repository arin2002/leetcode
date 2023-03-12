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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        
        // if(lists.size() == 0)
        //     return NULL;
        
        for(auto it : lists){
            while(it){
                ans.push_back(it->val);
                it = it->next;
            }
        }
        
        sort(ans.begin(),ans.end());
        int i = 0;
        ListNode *root = NULL, *prev;
        for(auto it : ans){
            ListNode *temp = new ListNode(it);
            
            if(i == 0){
                i = 1;
                root = temp;
                prev = root;
            }
            else{
                prev ->next = temp;
                prev = temp;
            }
        }
        
        return root;
    }
};