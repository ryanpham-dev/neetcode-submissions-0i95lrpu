
class Solution {

    // create a map of vertex and its adjacency list as a graph representation
    std::unordered_map<int, std::vector<int>> graph(std::vector<std::vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> adj_list{};
        for (const auto& edge : prerequisites) {
            int prerequisite = edge.front();
            int course = edge.back();
            adj_list[course].push_back(prerequisite);
            adj_list[prerequisite];
        }
        return adj_list;
    }

    // compute indegree of every vertex of the graph
    std::unordered_map<int, int> indegrees(std::unordered_map<int, std::vector<int>>& graph) {
        std::unordered_map<int, int> indegree_map(graph.size());
        for (const auto& [vertex, _] : graph) {
            indegree_map[vertex];
        }

        for (const auto& [vertex, adjacency_list] : graph) {
            for (const auto& neighbor : adjacency_list) {
                indegree_map[neighbor]++;
            }
        }
        return indegree_map;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> adj = graph(prerequisites);
        auto indegree_map = indegrees(adj);
        int finished = 0;
        std::queue<int> course_queue{};

        // enqueue all vertices with 0 indegrees;
        for (const auto& [vertex, indegree] : indegree_map) {
            if (indegree == 0) {
                course_queue.push(vertex);
            }
        }

        while (!course_queue.empty()) {
            auto course = course_queue.front();
            course_queue.pop();
            finished++;
            for (const auto neighbor : adj.at(course)) {
                indegree_map[neighbor]--;
                if (indegree_map[neighbor] == 0) {
                    course_queue.push(neighbor);
                }
            }
        }

        return finished == numCourses;
    }
};