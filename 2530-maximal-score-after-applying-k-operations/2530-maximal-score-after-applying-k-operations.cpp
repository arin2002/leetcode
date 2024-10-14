class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        long long ans = 0;
        priority_queue<int> pq;

        for(auto num: nums) pq.push(num);

        while(!pq.empty() && k--) {
            int top = pq.top();
            pq.pop();

            ans += top;
            pq.push(ceil(top/3.0));
        }

        return ans;
    }
};
