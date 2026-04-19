class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> output(2);
        for (auto i {0ul}; i < numbers.size(); ++i) {
            auto search {target - numbers[i]};
            auto l {i}, r {numbers.size() -1};
            while (l <= r) {
                auto m { l + (r - l) / 2 };
                if (numbers[m] == search) {
                    output[0] = l + 1;
                    output[1] = m + 1;
                    return output;
                }
                if (numbers[m] < search) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return output;

    }
};
