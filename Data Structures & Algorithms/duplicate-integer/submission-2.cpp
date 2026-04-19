class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> frequency {};
        for (const auto& num : nums) {
            if (frequency[num] == 1) {
                return true;
            }
            frequency[num] += 1;
        }
        return false;
    }
};