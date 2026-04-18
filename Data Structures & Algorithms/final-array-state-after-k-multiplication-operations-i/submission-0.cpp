
#include <ranges>
class Solution {
public:
    std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {

        auto comp = [&nums](int index1, int index2) {
            return nums[index1] > nums[index2] || (nums[index1] == nums[index2] && index1 > index2);
        };

        auto r = std::views::iota(0, static_cast<int>(nums.size()));
        std::priority_queue<int, std::vector<int>, decltype(comp)> minHeap{r.cbegin(), r.cend(),
                                                                           comp};

        for (int i = 0; i < k; ++i) {
            auto minIndex = minHeap.top();
            minHeap.pop();
            nums[minIndex] *= multiplier;
            minHeap.push(minIndex);
        }
        return nums;
    }
};
