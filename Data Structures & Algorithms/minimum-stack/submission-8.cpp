class MinStack {
    std::stack<long> s;
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
            long diff = s.top();
            s.pop();
            if (diff < 0) {
                min -= diff;
            }
        }
    }
    
    int top() {
        return s.top() < 0 ? static_cast<int>(min) : static_cast<int>(s.top() + min); 
    }
    
    int getMin() {
        return static_cast<int>(min);
    }
};
