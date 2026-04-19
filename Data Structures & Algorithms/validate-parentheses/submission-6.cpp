class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (const auto& c : s) {
        // std::cout << c;
        switch (c) {
            case '(':
            case '[':
            case '{':
                stack.push(c);
                break;
            case ')': {
                if (stack.empty() || stack.top() != '(') return false;
                stack.pop();
                break;
            }
            case ']' : 
            case '}' : {
                if (stack.empty() || c - stack.top() != 2) return false;
                stack.pop();
                break;
            }
            default: continue;
        }
    }
    return stack.empty();
    }
};
