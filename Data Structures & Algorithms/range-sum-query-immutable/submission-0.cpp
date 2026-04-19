class NumArray {
  std::vector<int> prefixSum_;

public:
  NumArray(vector<int> &nums) : prefixSum_(nums.size() + 1, 0) {
    std::inclusive_scan(nums.begin(), nums.end(), prefixSum_.begin() + 1);
  }

  int sumRange(int left, int right) {
    return prefixSum_[right + 1] - prefixSum_[left];
  }
};