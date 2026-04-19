class Solution {
public:
    int countElements(vector<int>& arr) {
        int count{};
        std::unordered_set<int> record (arr.begin(), arr.end());
        for (const auto& num : arr) {
            if (record.find(num + 1) != record.end()) {
                count++;
            }
        }
        return count;
    }
};
