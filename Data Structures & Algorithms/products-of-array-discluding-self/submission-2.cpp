#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <vector>
class Solution {
  public:
std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> res(nums.size());

    std::exclusive_scan(nums.begin(), nums.end(), res.begin(), 1, std::multiplies{});

    int suffix = 1;
    for (auto [r, num] : std::views::zip(res, nums) | std::views::reverse) {
        r *= suffix;
        suffix *= num;
    }

    return res;
}
};