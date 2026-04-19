class MinStack {
    std::stack<int> s;
    long min;

public:
    MinStack() {}
    
    void push(int val) {
        if (s.empty()) {
            min = val;
            s.push(0);
        } else {
            int diff = val - min;
            s.push(diff);
            if (val < min) {
                min = val;
            }
        }
    }
    
    void pop() {
        if (!s.empty()) {
            int diff = s.top();
            s.pop();
            if (diff < 0) {
                min -= diff;
            }
        }
    }
    
    int top() {
        return s.top() < 0 ? min : s.top() + min; 
    }
    
    int getMin() {
        return min;
    }
};
