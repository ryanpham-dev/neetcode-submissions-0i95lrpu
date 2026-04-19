class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            int num = nums.at(i);
            int diff_comp = target - num;
            if (record.find(diff_comp) != record.end()) {
                return vector<int> {record[diff_comp], i};
            }
            record.insert({num, i});
        }
        return {};
    }
};
