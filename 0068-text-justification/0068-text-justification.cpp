class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> result;
        int i = 0;
        
        while (i < words.size()) {
            int j = i, lineLength = 0;
            
            // Find the words that can fit in the current line
            while (j < words.size() && lineLength + words[j].length() + j - i <= maxWidth) {
                lineLength += words[j].length();
                ++j;
            }
            
            int spaces = maxWidth - lineLength;
            int diff = j - i - 1;  // Number of gaps between words
            
            // Construct the line by distributing spaces
            string line = words[i];
            if (j == words.size() || diff == 0) {
                // Left-justify the last line or when only one word in line
                for (int k = i + 1; k < j; ++k) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                // Distribute spaces between words
                int spacePerWord = spaces / diff;
                int extraSpaces = spaces % diff;
                for (int k = i + 1; k < j; ++k) {
                    line += string(spacePerWord + (k - i <= extraSpaces), ' ') + words[k];
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};
