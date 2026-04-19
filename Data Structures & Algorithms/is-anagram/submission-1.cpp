#include <ranges>
#include <algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::array<int, 26> hashtable {};
        for (const auto& [c1, c2] : std::views::zip(s, t)) {
            hashtable.at(c1 - 'a')++;
            hashtable.at(c2 - 'a')--;
        }
        for (const int& count : hashtable) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};
