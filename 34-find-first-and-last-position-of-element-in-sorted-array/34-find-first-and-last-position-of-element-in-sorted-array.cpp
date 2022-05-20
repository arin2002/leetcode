class Solution
{
    public:
        int firstocc(vector<int> &a, int l, int h, int x)
        {
            int ans = -1;
            while (l <= h)
            {

                int mid = (l + h) / 2;

                if (a[mid] == x)
                {
                    ans = mid;
                    h = mid - 1;
                }
                else if (a[mid] < x)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            return ans;
        }
    int lastocc(vector<int> &a, int l, int h, int x)
    {
        int ans = -1;
        while (l <= h)
        {

            int mid = (l + h) / 2;

            if (a[mid] == x)
            {
                ans = mid;
                l = mid + 1;
            }
            else if (a[mid] < x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        vector<int> v;

        v.push_back(firstocc(nums, low, high, target));
        v.push_back(lastocc(nums, low, high, target));
        return v;
    }
};