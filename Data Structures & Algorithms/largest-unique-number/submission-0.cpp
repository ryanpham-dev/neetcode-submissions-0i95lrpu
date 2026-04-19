class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int output = -1;
        std::unordered_map<int, int> hash_map{};
        for(const auto& num : nums) {
            hash_map[num]++;
        }
        for (const auto& [key, value] : hash_map) {
            if (value == 1 && key > output) {
                output = key;
            }
        }
        return output;
    }
};
