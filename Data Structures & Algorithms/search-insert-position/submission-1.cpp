class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto iter = std::lower_bound(nums.cbegin(), nums.cend(), target);
        return static_cast<int>(std::distance(nums.cbegin(), iter));
    }
};