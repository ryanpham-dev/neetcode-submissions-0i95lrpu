
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int threshHold) {
        std::priority_queue<int, std::vector<int>, std::greater<>> MinHeap{};
        for (const auto& num : nums) {
            MinHeap.emplace(num);
            if (static_cast<int>(MinHeap.size()) > threshHold) {
                MinHeap.pop();
            }
        }
        return MinHeap.top();
    }
};