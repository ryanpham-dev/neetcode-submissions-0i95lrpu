
class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<>> MinHeap{};
    int threshhold{};

public:
    KthLargest(int k, std::vector<int>& nums) : threshhold(k) {
        for (const int num : nums) {
            add(num);
        }
    }
    int add(int value) {

        MinHeap.push(value);
        if(static_cast<int>(MinHeap.size()) > threshhold) {
            MinHeap.pop();
        }
        return MinHeap.top();
    }
};