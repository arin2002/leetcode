class Solution {
    inline bool isCapital(char ch) { return (ch >= 'A' && ch <= 'Z'); }
    inline bool isLower(char ch) { return (ch >= 'a' && ch <= 'z'); }
    inline bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }

public:
    string countOfAtoms(string s) {
        int n = (int)s.length();
        map<string, int> ans;
        stack<unordered_map<string, int>> stk;
        unordered_map<string, int> mp;
        stk.push(mp);

        for (int i = 0; i < n;) {
            if (isCapital(s[i])) {
                string element;
                int count = 0;
                element += s[i++];
                while (i < n && isLower(s[i]))
                    element += s[i++];
                while (i < n && isDigit(s[i]))
                    count = count * 10 + (s[i++] - '0');
                stk.top()[element] += (count == 0 ? 1 : count);
            } else if (s[i] == '(') {
                stk.push(mp);
                i++;
            } else if (s[i] == ')') {
                int count = 0;
                i++;
                while (i < n && isDigit(s[i]))
                    count = count * 10 + (s[i++] - '0');
                if (count == 0)
                    count = 1;

                auto topMap = stk.top();
                stk.pop();
                for (auto& it : topMap) {
                    stk.top()[it.first] += it.second * count;
                }
            }
        }

        while (!stk.empty()) {
            for (auto& it : stk.top()) {
                ans[it.first] += it.second;
            }
            stk.pop();
        }

        string result;
        for (auto& p : ans) {
            result += p.first + (p.second > 1 ? to_string(p.second) : "");
        }
        return result;
    }
};
