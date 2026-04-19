#include <functional>
#include <numeric>
#include <ranges>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<int> prefix(n);
    std::vector<int> suffix(n);

    std::exclusive_scan(nums.begin(), nums.end(), prefix.begin(), 1,
                        std::multiplies{});
    std::exclusive_scan(nums.rbegin(), nums.rend(), suffix.rbegin(), 1,
                        std::multiplies{});

    return std::views::zip_transform(std::multiplies{}, prefix, suffix) |
           std::ranges::to<std::vector<int>>();
  }
};