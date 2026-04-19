class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int length = nums.size();
        nums.resize(2 * length);
        for (int i = 0; i < length; ++i) {
            nums[length+ i] = nums[i];
        }
        return nums;
}
};