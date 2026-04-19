class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> products{1};
    int size{static_cast<int>(nums.size())};
    // calculate prefix products
    for (int i = 1; i < size; ++i) {
      products.push_back(products[i - 1] * nums[i - 1]);
    }

    // calculate suffix products
    int num = 1;
    for (int i = size - 1; i >= 0; --i) {
      products[i] *= num;
      num *= nums[i];
    }
    return products;
  }
};
