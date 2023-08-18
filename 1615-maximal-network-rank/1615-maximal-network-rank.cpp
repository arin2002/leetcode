class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> isConnected(n, vector<int>(n, 0));
        vector<int> cityRank(n, 0);
        
        for (const auto& road : roads) {
            isConnected[road[0]][road[1]] = isConnected[road[1]][road[0]] = 1;
            cityRank[road[0]]++;
            cityRank[road[1]]++;
        }
        
        int maximalRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = cityRank[i] + cityRank[j] - isConnected[i][j];
                maximalRank = max(maximalRank, rank);
            }
        }
        
        return maximalRank;
    }
};
