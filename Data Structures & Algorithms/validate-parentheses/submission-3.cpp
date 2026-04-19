class Solution {
public:
    bool isValid(string s) {
        vector<char> char_stack;
        // if (s.size() == 1) return false;
        for (char& c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': {
                    char_stack.push_back(c);
                    break;
                }
                case ')': {
                    if (char_stack.empty() || char_stack.back() != '(') {
                        return false;
                    }
                    char_stack.pop_back();
                    break;
                }
                case '}': {
                    if (char_stack.empty() || char_stack.back() != '{') {
                        return false;
                    }
                    char_stack.pop_back();
                    break;
                }
                case ']': {
                    if (char_stack.empty() || char_stack.back() != '[') {
                        return false;
                    }
                    char_stack.pop_back();
                    break;
                }
                default: return false;
            }
        }
        return char_stack.empty();
    }
};
