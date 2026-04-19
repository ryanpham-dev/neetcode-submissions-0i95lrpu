class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        int left = 0;
        int right = 1;
        int size = static_cast<int>(nums.size());
        while (left < right) {
            if (nums[left] == nums[right] && std::abs(left - right) <= k) {
                return true;
            }
            if (right == size - 1 || (nums[left] == nums[right])) {
                left++;
            }

            else if (nums[left] != nums[right]) {
                right++;
            }
        }

        return false;
    }
};