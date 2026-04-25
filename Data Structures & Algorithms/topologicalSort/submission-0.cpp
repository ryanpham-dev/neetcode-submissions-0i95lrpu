class Solution {
public:
    std::vector<int> topologicalSort(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> indegrees(n);
        for (const auto& edge : edges) {
            indegrees[edge.back()]++;
        }
        std::vector<std::vector<int>> adjList(n);
        for (const auto& edge : edges) {
            int startingVertex = edge.front();
            int endingVertex = edge.back();
            adjList[startingVertex].emplace_back(endingVertex);
        }
        std::queue<int> frontier;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0) {
                frontier.emplace(i);
            }
        }
        std::vector<int> topoSort;
        while (!frontier.empty()) {
            int current = frontier.front();
            frontier.pop();
            topoSort.emplace_back(current);
            for (const int neighbor : adjList[current]) {
                if (--indegrees[neighbor] == 0) {
                    frontier.push(neighbor);
                }
            }
        }
        return topoSort.size() != adjList.size() ? std::vector<int>{} : topoSort;
    }
};
