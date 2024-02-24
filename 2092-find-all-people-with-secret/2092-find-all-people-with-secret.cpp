class Solution {
    struct CustomPairComparison {
        inline bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
            return lhs.second > rhs.second;
        }
    };

    using adj_list_t = std::vector<std::vector<std::pair<int, int>>>;
    using visited_t = std::unordered_set<int>;
    using queue_t = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CustomPairComparison>;

    void bfs(const adj_list_t& adj_list, visited_t& visited) {
        queue_t queue;
        queue.push({0, 0});
        while (!queue.empty()) {
            auto [current_person, current_time] = queue.top();
            queue.pop();

            visited.insert(current_person);

            for (const auto& neighbor: adj_list[current_person]) {
                if (!visited.contains(neighbor.first) && neighbor.second >= current_time) {
                    queue.push(neighbor);
                }
            }
        }
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        adj_list_t adj_list(n);
        adj_list[0].push_back({firstPerson, 0});
        adj_list[firstPerson].push_back({0, 0});
        for (const auto& e: meetings) {
            adj_list[e[0]].push_back({e[1], e[2]});
            adj_list[e[1]].push_back({e[0], e[2]});
        }

        visited_t visited;
        bfs(adj_list, visited);

        return vector<int>(visited.begin(), visited.end());
    }
};
