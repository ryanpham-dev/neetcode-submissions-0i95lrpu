class Solution {
public:
    
    std::vector<std::vector<int>> highFive(std::vector<std::vector<int>>& items) {

        std::vector<std::vector<int>> result{};
        std::map<int, std::priority_queue<int, std::vector<int>, std::greater<>>> record{};

        for (const auto& item : items) {
            int id = item.front();
            int score = item.back();
            record[id].emplace(score);
            if (record[id].size() > 5) {
                record[id].pop();
            }
        }

        for (const auto& pair : record) {
            int id = pair.first;
            int sum = 0;
            auto minHeap = pair.second;
            while (!minHeap.empty()) {
                sum += minHeap.top();
                minHeap.pop();
            }
            std::vector<int> num {id, sum / 5};
            result.emplace_back(num);
        }

        return result;
    }
};
