class Solution {
private:
    void floyd(vector<vector<int>>& distance, int n){
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][k] < 1e9 && distance[k][j] < 1e9) {  // Check to avoid overflow
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }
    }

    int fewestreachable(int distanceThreshold, int n, vector<vector<int>>& distance) {
        int fewestcount = n;
        int res = -1;
        for (int i = 0; i < n; i++) {
            int underthreshold = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (distance[i][j] <= distanceThreshold) {
                    underthreshold++;
                }
            }
            if (underthreshold <= fewestcount) {
                fewestcount = underthreshold;
                res = i;
            }
        }
        return res;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int INF = 1e9 + 7;
        vector<vector<int>> distance(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            distance[from][to] = weight;
            distance[to][from] = weight;
        }
        floyd(distance, n);
        return fewestreachable(distanceThreshold, n, distance);
    }
};
