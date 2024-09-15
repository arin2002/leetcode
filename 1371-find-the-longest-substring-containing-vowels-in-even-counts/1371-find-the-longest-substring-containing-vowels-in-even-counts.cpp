class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Map to store the first occurrence of each state string
        unordered_map<string, int> mp;

        // State array to track the parity of vowels (a, e, i, o, u)
        vector<int> state(5, 0);

        // Initial state where all vowels have appeared an even number of times
        string cst = "00000";
        
        // Add the initial state with index -1 (before the string starts)
        mp[cst] = -1;
        
        // Variable to store the length of the longest valid substring
        int ans = 0;

        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Update the state of vowels based on the current character
            if (s[i] == 'a') {
                state[0] = (state[0] + 1) % 2;  // Toggle the parity for 'a'
            }
            else if (s[i] == 'e') {
                state[1] = (state[1] + 1) % 2;  // Toggle the parity for 'e'
            }
            else if (s[i] == 'i') {
                state[2] = (state[2] + 1) % 2;  // Toggle the parity for 'i'
            }
            else if (s[i] == 'o') {
                state[3] = (state[3] + 1) % 2;  // Toggle the parity for 'o'
            }
            else if (s[i] == 'u') {
                state[4] = (state[4] + 1) % 2;  // Toggle the parity for 'u'
            }

            // Convert the state array into a binary string representing the current vowel states
            cst = "";
            for (int j = 0; j < 5; j++) {
                cst += to_string(state[j]);
            }

            // If this state has been seen before, calculate the length of the substring
            if (mp.find(cst) != mp.end()) {
                ans = max(ans, i - mp[cst]);  // Update the answer with the longest valid substring
            } 
            // If the state is new, store the index in the map
            else {
                mp[cst] = i;
            }
        }

        // Return the length of the longest valid substring
        return ans;
    }
};
