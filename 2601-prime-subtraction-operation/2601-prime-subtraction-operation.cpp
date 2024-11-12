class Solution {
public:
    vector<int> getPrimes(int max_num) {
        vector<bool> is_p(max_num + 1, true);
        is_p[0] = is_p[1] = false;

        for (int p = 2; p * p <= max_num; p++) {
            if (is_p[p]) {
                for (int i = p * p; i <= max_num; i += p)
                    is_p[i] = false;
            }
        }

        vector<int> primes;

        for (int p = 2; p <= max_num; p++) {
            if (is_p[p])
                primes.push_back(p);
        }

        return primes;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = getPrimes(1000);
        vector<vector<int>> pv(n);

        for (int i = 0; i < n; i++) {
            pv[i].push_back(nums[i]);

            for (auto p : primes) {
                if (p < nums[i])
                    pv[i].push_back(nums[i] - p);
                else
                    break;
            }

            sort(pv[i].begin(), pv[i].end());
            pv[i].erase(unique(pv[i].begin(), pv[i].end()), pv[i].end());
        }

        int last = INT32_MIN;

        for (int i = 0; i < n; i++) {
            int idx =
                upper_bound(pv[i].begin(), pv[i].end(), last) - pv[i].begin();
            if (idx == pv[i].size())
                return false;
            last = pv[i][idx];
        }

        return true;
    }
};