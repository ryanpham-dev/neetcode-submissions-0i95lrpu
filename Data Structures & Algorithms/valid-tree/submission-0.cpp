
class Solution {
    vector<list<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<list<int>> adjList(n);
        for (const auto edge : edges) {
            int from = edge.front();
            int to = edge.back();
            adjList[from].emplace_back(to);
            adjList[to].emplace_back(from);
        }
        return adjList;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (static_cast<int>(edges.size()) != n - 1) {
            return false;
        }

        auto graph = buildGraph(n, edges);
        std::queue<int> frontier;
        std::vector<int> degrees(n);
        for (const auto& adjacency : graph) {
            for (const int neighbor : adjacency) {
                degrees[neighbor]++;
            }
        }

        for (int i = 0; i < degrees.size(); ++i) {
            if (degrees[i] <= 1) {
                frontier.push(i);
            }
        }

        int removed = 0;
        while (!frontier.empty()) {
            int current = frontier.front();
            frontier.pop();
            removed++;
            for (const int neighbor : graph[current]) {
                degrees[neighbor]--;
                if (degrees[neighbor] == 1) {
                    frontier.push(neighbor);
                }
            }
        }

        return removed == n;
    }
};