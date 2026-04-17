class Solution {
public:
    int findJudge(int people, std::vector<std::vector<int>>& trust) {
        int judge = -1;
        std::unordered_map<int, std::unordered_set<int>> graph(people);
        for (const auto& relation : trust) {
            int from = relation.front();
            int to = relation.back();
            graph[from].insert(to);
            graph[to];
        }

        auto it = std::find_if(graph.begin(), graph.end(),
                               [](const auto& relation) { return relation.second.size() == 0; });
        if (it != graph.end()) {
            int potential = it->first;
            int trust_number = 0;
            for (const auto& [_, trustedList] : graph) {
                if (trustedList.count(potential) == 1) {
                    trust_number++;
                }
            }
            if (trust_number == people - 1) {
                return potential;
            }
        }

        return judge;
    }
};