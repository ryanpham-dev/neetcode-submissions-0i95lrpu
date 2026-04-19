class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            auto key = nums[i];
            int j = i - 1;
            auto prev = nums[j];
            while (j >= 0 && key < prev) {
                nums[j + 1] = prev;
                j--;
                prev = nums[j];
            }
            nums[j + 1] = key;
        }
        return nums;
    }
};