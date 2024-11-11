class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0;
        int currentOr = 0;
        vector<int> bits(32, 0);
        
        for (int right = 0; right < n; right++) 
        { 
            currentOr |= nums[right];
            
            for (int bit = 0; bit < 32; bit++) 
            {
                if (nums[right] & (1 << bit)) 
                {
                    bits[bit]++;
                }
            }

            while (left <= right && currentOr >= k) 
            {
                minLength = min(minLength, right - left + 1);
                int newOr = 0;

                for (int bit = 0; bit < 32; bit++) 
                {
                    if (nums[left] & (1 << bit)) 
                    {
                       bits[bit]--;
                    }
                    if (bits[bit] > 0)
                    {
                       newOr |= (1 << bit);
                    }
                }
                currentOr = newOr;
                left++;
            }
        }

        return (minLength == INT_MAX) ? -1 : minLength;
    }
};
