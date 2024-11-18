class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0) return result;

        for (int i = 0; i < n; i++) {
            int sum = 0, step = 0, j = i;
            while (step < abs(k)) {
                j = (j + (k > 0 ? 1 : -1) + n) % n;
                sum += code[j];
                step++;
            }
            result[i] = sum;
        }
        return result;
    }
};
