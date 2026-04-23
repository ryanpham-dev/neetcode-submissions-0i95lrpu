#include <queue>
#include <unordered_map>
#include <unordered_set>
class Graph {
    std::unordered_map<int, std::unordered_set<int>> graph{};

public:
    Graph() = default;
    void addEdge(int src, int dst) {
        graph[src].insert(dst);
        graph[dst];
    }

    bool removeEdge(int src, int dst) { return static_cast<bool>(graph[src].erase(dst)); }

    bool hasPath(int src, int dst) {
        std::unordered_set<int> visited{};
        std::queue<int> frontier{};
        frontier.push(src);
        visited.insert(src);
        while (!frontier.empty()) {
            auto size = frontier.size();
            for (auto i = 0ul; i < size; ++i) {
                int current = frontier.front();
                frontier.pop();
                if (current == dst) {
                    return true;
                }
                for (const int neighbor : graph.at(current)) {
                    if (!visited.contains(neighbor)) {
                        visited.insert(neighbor);
                        frontier.push(neighbor);
                    }
                }
            }
        }
        return false;
    }
};
