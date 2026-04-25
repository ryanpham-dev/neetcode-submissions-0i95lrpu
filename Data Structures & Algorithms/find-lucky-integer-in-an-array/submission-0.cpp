class Solution {
public:
    int findLucky(vector<int>& arr) {
        int output {-1};
        std::unordered_map<int, int> freq{};
        for (const int num : arr) {
            ++freq[num];
        }
        for (const auto& [key, value] : freq) {
            if (key == value) {
                output = std::max(output, key);
            }
        }
        return output;
    }
};