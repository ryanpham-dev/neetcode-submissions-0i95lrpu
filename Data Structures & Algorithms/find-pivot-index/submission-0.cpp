class Solution {
public:
  int pivotIndex(std::vector<int> &num) {
    std::vector<int> prefixSum(num.size() + 1);
    std::inclusive_scan(num.begin(), num.end(), prefixSum.begin() + 1);
    int size = static_cast<int>(num.size());
    for (int i = 0; i < size; ++i) {
      int left = i == 0 ? 0 : prefixSum[i] - prefixSum[0];
      int right = i == size ? 0 : prefixSum.back() - prefixSum[i + 1];
      if (left == right) {
        return i;
      }
    }
    return -1;
  }
};