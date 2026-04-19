class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index = 0;
        auto left = 0ul;
        auto right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] >  nums[mid - 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return index;
    }
};