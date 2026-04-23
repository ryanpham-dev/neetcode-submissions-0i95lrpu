class MovingAverage {
    std::deque<int> stream;
    unsigned long long window;

public:
    MovingAverage(int size) : window(static_cast<unsigned long long>(size)) { }
    double next(int val) {
        if (stream.size() == window) {
            stream.pop_front();
        }
        stream.push_back(val);
        int sum{};
        int counter{};
        for (int num : stream) {
            sum += num;
            counter++;
        }
        return sum * 1.0 / counter;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
