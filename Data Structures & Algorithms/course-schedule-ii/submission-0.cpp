
class Solution {
    std::unordered_map<int, std::vector<int>> preMap(int numCourses,
                                                     std::vector<std::vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> output(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            output[i] = {};
        }
        for (const auto& courses : prerequisites) {
            int course = courses.front();
            int prereg = courses.back();
            output[prereg].push_back(course);
        }
        return output;
    }

    std::unordered_map<int, int> indegrees(std::unordered_map<int, std::vector<int>>& preMap) {
        std::unordered_map<int, int> indegrees(preMap.size());
        for (const auto& [prereg, _] : preMap) {
            indegrees[prereg] = 0;
        }

        for (const auto& [prereg, courses] : preMap) {
            for (const auto& course : courses) {
                indegrees[course]++;
            }
        }
        return indegrees;
    }

public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> output;
        auto map = preMap(numCourses, prerequisites);
        auto indegree = indegrees(map);
        std::queue<int> queue;
        for (const auto& [course, indegree] : indegree) {
            if (indegree == 0) {
                queue.push(course);
            }
        }

        while (!queue.empty()) {
            auto course = queue.front();
            queue.pop();
            output.push_back(course);
            for (const auto& other_courses : map.at(course)) {
                indegree[other_courses]--;
                if (indegree[other_courses] == 0) {
                    queue.push(other_courses);
                }
            }
        }

        if (output.size() != map.size()) {
            return {};
        }

        return output;
    }
};
