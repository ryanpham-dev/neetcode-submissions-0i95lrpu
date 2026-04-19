class MyStack {
    std::queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        // if (!empty()) {
        int element = top();
        int times = q.size();
        for(int i = 0; i < times - 1; ++i) {
            int e = q.front();
            q.pop();
            q.push(e);
        }
        q.pop();
        return element;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */