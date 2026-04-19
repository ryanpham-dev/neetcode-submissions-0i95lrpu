#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> output{};
        output.reserve(k);

        std::unordered_map<int, int> frequencyTable{};
        for (const auto num : nums) {
            frequencyTable[num]++;
        }

        // auto comparator = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        //     return a.first > b.first;
        // };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>>
            minHeap{};
        for (const auto [value, freq] : frequencyTable) {
            minHeap.emplace(freq, value);
            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }
        while (!minHeap.empty()) {
            output.emplace_back(minHeap.top().second);
            minHeap.pop();
        }

        return output;
    }
};