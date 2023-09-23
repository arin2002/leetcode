class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
    sort(words.begin(), words.end(), [](string a, string b) {
        return a.size() < b.size();
    });
    
    unordered_map<string, int> chainLength; // Map to store chain lengths
    
    int ans = 1;
    
    for(const string& word : words) {
        int currentChainLength = 1;
        
        // Generate all possible predecessors of 'word'
        for(int i = 0; i < word.size(); i++) {
            string predecessor = word.substr(0, i) + word.substr(i + 1);
            
            // Check if 'predecessor' is in the map
            if(chainLength.find(predecessor) != chainLength.end()) {
                currentChainLength = max(currentChainLength, chainLength[predecessor] + 1);
            }
        }
        
        // Update the chain length for 'word'
        chainLength[word] = currentChainLength;
        
        // Update the overall answer
        ans = max(ans, currentChainLength);
    }
    
    return ans;
    }
};
