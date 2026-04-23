class Solution {
    std::vector<std::list<int>> edgeToGraph(int vertices, std::vector<std::vector<int>>& edges) {
    std::vector<std::list<int>> graph(vertices);
    for (const auto& edge : edges) {
        int startingVertex = edge.front();
        int endingVertex = edge.back();
        graph[startingVertex].emplace_back(endingVertex);
        graph[endingVertex].emplace_back(startingVertex);
    }
    return graph;
}
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        auto graph = edgeToGraph(n, edges);
        std::vector<int> visited(graph.size(), 0);
    int connectedComponents = 0;

    for (int i = 0; i < (int)graph.size(); ++i) {
        if (visited[i] == 0) {
            std::vector<int> components{};
            std::stack<int> frontier{};
            frontier.push(i);
            visited[i] = 1;

            while (!frontier.empty()) {
                int current = frontier.top();
                frontier.pop();
                components.push_back(current);
                for (const int neighbor : graph[current]) {
                    if (visited[neighbor] == 0) {
                        visited[neighbor] = 1;
                        frontier.push(neighbor);
                    }
                }
            }

            if (!components.empty()) {
                connectedComponents++;
            }
        }
    }

    return connectedComponents;
    }
};
