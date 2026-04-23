
class MovingAverage {
    std::deque<int> stream;
    int window{};
    int windowSum{};
    int count{};

public:
    MovingAverage(int size) : window(size) {}
    double next(int val) {
        if (static_cast<int>(stream.size()) == window) {
            int last = stream.front();
            stream.pop_front();
            windowSum -= last;
            count--;
        }
        stream.push_back(val);
        count++;
        windowSum += val;
        return windowSum * 1.0 / std::min(count, window);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
