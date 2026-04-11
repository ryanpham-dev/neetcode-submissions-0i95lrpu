
class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& array, int kClosest, int target) {
        std::vector<int> output;

        output.reserve(kClosest);

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>> max_heap{};
        for (const int value : array) {
            max_heap.emplace(std::abs(value - target), value);
            if (static_cast<int>(max_heap.size()) > kClosest) {
                max_heap.pop();
            }
        }

        while (!max_heap.empty()) {
            int element = max_heap.top().second;
            max_heap.pop();
            output.emplace_back(element);
        }
        std::sort(output.begin(), output.end());
        return output;
    }
};