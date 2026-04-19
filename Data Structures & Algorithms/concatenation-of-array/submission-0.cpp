class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int length =  2 * nums.size();
        vector<int> new_v(length, 0);
        new_v.reserve(length);
        for (int i = 0; i < length; ++i) {
            new_v[i] = nums[i % nums.size()];
        }
        return new_v;
    }
};