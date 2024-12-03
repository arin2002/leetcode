class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        size_t size = s.size();
        s.resize(s.size() + spaces.size());
        size_t last = s.size();
        for (size_t i = spaces.size(); i != 0; --i) {
            const int space_pos = spaces[i - 1];
            const int len = size - space_pos;
            std::copy_backward(&s[space_pos], &s[size], &s[last]);
            s[space_pos + i - 1] = ' ';
            last -= len + 1;
            size = space_pos;
        }
        return s;
    }
};
