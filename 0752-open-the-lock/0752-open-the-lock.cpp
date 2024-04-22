class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<string> q;
    q.push("0000");
    visited.insert("0000");
    int moves = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string current = q.front();
            q.pop();
            if (current == target) {
                return moves;
            }
            if (dead.count(current)) {
                continue;
            }
            for (int j = 0; j < 4; ++j) {
                for (int k = -1; k <= 1; k += 2) {
                    string next = current;
                    next[j] = ((next[j] - '0' + k + 10) % 10) + '0';
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        ++moves;
    }

    return -1;
}
};
