class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize a vector to store the minimum frequency of each character in all words.
        vector<int> minFreq(26, INT_MAX);

        // Iterate over each word in the words array.
        for(int i = 0; i < words.size(); i++) {
            // Initialize a frequency vector to count the frequency of each character in the current word.
            vector<int> currFreq(26, 0);
            // Count the frequency of each character in the current word.
            for(int j = 0; j < words[i].size(); j++) 
                currFreq[words[i][j] - 'a']++;
            // Update the minFreq vector to keep the minimum frequency of each character.
            for(int j = 0; j < 26; j++) 
                minFreq[j] = min(minFreq[j], currFreq[j]);
        }

        // Prepare the result array to return the common characters.
        vector<string> commonCharsList;
        for(int i = 0; i < 26; i++) {
            // Add the character 'i' to the result array as many times as its minimum frequency.
            while(minFreq[i] != 0) {
                commonCharsList.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }
        return commonCharsList;
    }
};
