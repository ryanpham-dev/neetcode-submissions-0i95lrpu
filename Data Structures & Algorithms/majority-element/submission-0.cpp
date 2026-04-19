
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freq{};
        int output = nums.front();
        int threshold = static_cast<int>(nums.size()) / 2;
        for (const auto& num : nums) {
            freq[num]++;
        }
        for (const auto [num, frequency] : freq) {
            if (frequency >= threshold) {
                output = num;
            }
        }
        return output;
    }
};