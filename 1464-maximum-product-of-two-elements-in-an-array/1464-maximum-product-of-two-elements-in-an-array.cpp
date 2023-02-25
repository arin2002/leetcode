class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        priority_queue<int> pq(nums.begin(),nums.end());
        
        int a = pq.top()-1;
        pq.pop();
        int b = pq.top()-1;
        pq.pop();
        
        return a*b;
    }
};