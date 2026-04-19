class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odds = 0;
        std::unordered_map<char, int> freq{};
        for (const auto& ch : s) {
            freq[ch]++;
            if (freq[ch] % 2 == 0) {
                odds--;
            } else {
                odds++;
            }
        }
        return odds <= 1;
    }
};
