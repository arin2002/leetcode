class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        vector<int> frequencies(26, 0);
        for (char task : tasks) {
            frequencies[task - 'A']++;
        }
        
        // Sort the frequencies in descending order
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        // Get the maximum frequency
        int maxFreq = frequencies[0];
        
        // Calculate the number of intervals required
        int idleTime = (maxFreq - 1) * n;
        for (int i = 1; i < frequencies.size() && frequencies[i] > 0; i++) {
            idleTime -= min(frequencies[i], maxFreq - 1);
        }
        
        idleTime = max(0, idleTime);
        
        return tasks.size() + idleTime;
    }
};
