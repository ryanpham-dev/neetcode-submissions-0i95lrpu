class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> record{};
        int size = static_cast<int>(nums.size()); 
        for (int i = 0; i < size; ++i) {
            int complement = target - nums[i];
            if (record.find(complement) != record.end()) {
                return {record[complement], i};
            }
            record.emplace(nums[i], i);
        }  
        return {};
    }
};
