class Solution {
public:
    int mod = 1e9 + 7;
    long long rec(vector<int>& arr, int root, unordered_map<long long, long long>& dp)
    {
        if(dp.count(root))return dp[root];

        long long ans = 1;
        for(int i = 0; i < arr.size(); i++)
        {
            if(root % arr[i] == 0)
            {
                int tmp = root / arr[i];
                auto x = lower_bound(arr.begin(), arr.end(), tmp) - arr.begin();
                if(x < arr.size() && arr[x] == tmp)
                {
                    ans = (ans + rec(arr, tmp, dp) * rec(arr, arr[i], dp)) % mod;
                }
            }
        }

        return dp[root] = ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(begin(arr), end(arr));

        unordered_map<long long, long long> dp;

        long long ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            ans = (ans + rec(arr, arr[i], dp)) % mod;
        }

        return ans;
    }
};