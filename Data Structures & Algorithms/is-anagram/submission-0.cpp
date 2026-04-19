class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int hashtable[26] {};
        for (int i = 0; i < s.size(); ++i) {
            hashtable[static_cast<int>(s[i]) - static_cast<int>('a')] += 1;
            hashtable[static_cast<int>(t[i]) - static_cast<int>('a')] -= 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (hashtable[i] != 0) {
                return false;
            }
        }
        return true;
        
        
    }
};
