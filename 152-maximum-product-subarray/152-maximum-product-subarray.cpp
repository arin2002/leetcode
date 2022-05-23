class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int n = nums.size();
            int ans1 = INT_MIN, ans2 = INT_MIN;
            int p_max = 1, n_max = 1;

            for (auto i: nums)
            {
                p_max *= i;
                ans1 = max(p_max, ans1);

                if (p_max == 0)
                    p_max = 1;
            }
            p_max = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                p_max *= nums[i];
                ans2 = max(p_max, ans2);

                if (p_max == 0)
                    p_max = 1;
            }
            
            return max(ans1,ans2);
        }
};