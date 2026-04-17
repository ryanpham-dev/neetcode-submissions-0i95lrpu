class Solution {

    // create a map of vertex and its adjacency list as a graph representation
    std::unordered_map<int, std::vector<int>> graph(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> adj_list{};
        for (int i = 0; i < numCourses; ++i) adj_list[i] = {};
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];
            adj_list[prerequisite].push_back(course);
        }
        return adj_list;
    }

    // compute indegree of every vertex of the graph
    std::unordered_map<int, int> indegrees(std::unordered_map<int, std::vector<int>>& graph) {
        std::unordered_map<int, int> indegree_map(graph.size());
        for (const auto& [vertex, _] : graph) {
            indegree_map[vertex] = 0;
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
        std::unordered_map<int, std::vector<int>> adj = graph(numCourses, prerequisites);
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