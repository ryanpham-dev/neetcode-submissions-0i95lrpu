
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odds = 0;
        std::unordered_map<char, int> freq{};
        for (const auto& ch : s) {
            freq[ch]++;
        }
        for (const auto& [key, value] : freq) {
            if (value % 2 != 0) {
                odds++;
            }
        }
        return odds <= 1;
    }
};
