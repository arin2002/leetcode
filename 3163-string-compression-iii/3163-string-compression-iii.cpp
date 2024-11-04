class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        char preFix = word[0];
        int count = 1;
        string comp = "";

        for (int i = 1; i < n; i++) {
            if (word[i] != preFix || count >= 9) {
                comp.push_back(count + '0');
                comp.push_back(preFix);
                preFix = word[i];
                count = 1;
            } else {
                count++;
            }
        }
        comp.push_back(count + '0');
        comp.push_back(preFix);
        return comp;
    }
};
