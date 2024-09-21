class Solution {
public:
    void rec(int n, vector<int> &res, int prev) {
        // early return if it cannot be in result vector
        if(prev <= 0 || prev > n) {
            return;
        }
        // add into result vector
        res.push_back(prev);

        // next level of recursion
        prev = prev * 10;
        for(int i = 0; i < 10; i++) {
            int now = prev + i;
            rec(n, res, now);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        // first level of recursion
        for(int i = 0; i < 10; i++) {
            rec(n, res, i);
        }
        return res;
    }
};
