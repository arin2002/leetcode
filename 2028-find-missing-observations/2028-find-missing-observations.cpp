class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // Step 1: Calculate the total sum required for all rolls (existing + missing)
        int totalsum = (n + rolls.size()) * mean;

        // Step 2: Calculate the sum of the existing rolls
        int msum = accumulate(rolls.begin(), rolls.end(), 0);

        // Step 3: Calculate the sum needed for missing rolls
        int nsum = totalsum - msum;

        // Step 4: Check if it's possible to distribute the sum among n rolls (each between 1 and 6)
        if (nsum < n || double(nsum) / n > 6.0) {
            return {};  // Impossible case
        }

        // Step 5: Distribute the sum
        int quotient = nsum / n;  // Base value for each missing roll
        int remainder = nsum % n; // Remainder to distribute
        
        vector<int> ans(n, quotient);  // Initialize all rolls with the base value
        for (int i = 0; i < remainder; i++) {
            ans[i]++;  // Distribute the remainder by adding 1 to the first few elements
        }

        return ans;
    }
};
