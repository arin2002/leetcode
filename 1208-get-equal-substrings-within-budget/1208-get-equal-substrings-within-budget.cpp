class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        
        int msum = 0;
        int wsum = 0;
        int start = 0;

        for(int end = 0; end < s.size(); end++) {
            wsum += abs(s[end]-t[end]);
            while (wsum > maxcost) {
                wsum -= abs(s[start]-t[start]);
                start++;
            }
            msum = max(msum, end - start + 1);
        }
        
        return msum;
    }
};
