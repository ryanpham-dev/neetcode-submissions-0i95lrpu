// not O(1)
class Deque {
    std::vector<int> q;
public:
    Deque() {
        q.reserve(64);
    }

    bool isEmpty() {
        return q.size() == 0;
    }

    void append(int value) {
        q.push_back(value);
    }

    void appendleft(int value) {
        q.insert(q.begin(), value);
    }

    int pop() {
        if (isEmpty()) return -1;
        int out = q.back();
        q.pop_back();
        return out;
    }

    int popleft() {
        if (isEmpty()) return -1;
        int out = q.front();
        q.erase(q.begin());
        return out;
    }
};
