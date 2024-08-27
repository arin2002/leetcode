using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, double>>> graph(n);
        
        // Fill the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        
        // Max-heap priority queue to store (probability, node)
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start);
        
        // Vector to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        
        // Dijkstra-like algorithm
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            if (node == end) {
                return prob; // Early exit if we've reached the end node
            }
            
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.emplace(newProb, neighbor);
                }
            }
        }
        
        return 0.0; // Return 0 if there's no path from start to end
    }
};
