#include <vector>

using std::vector;
class MinHeap {
    vector<int> heapqueue_;
    int size_{};
    int parent_index(int index) { return (index - 1) / 2; }
    int left_child(int index) { return index * 2 + 1; }
    int right_child(int index) { return index * 2 + 2; }

    void upheap(int index) {
        while (index > 0) {
            int parent = parent_index(index);
            if (heapqueue_[index] < heapqueue_[parent]) {
                std::swap(heapqueue_[index], heapqueue_[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int index) {
        while (true) {
            int smallest = index;
            int left = left_child(index);
            int right = right_child(index);

            if (left < size_ && heapqueue_[left] < heapqueue_[smallest]) {
                smallest = left;
            }

            if (right < size_ && heapqueue_[right] < heapqueue_[smallest]) {
                smallest = right;
            }

            if (smallest != index) {
                std::swap(heapqueue_[index], heapqueue_[smallest]);
                index = smallest;  // follow the element down
            } else {
                break;
            }
        }
    }

public:
    MinHeap() = default;

    void push(int val) {
        heapqueue_.push_back(val);
        size_++;
        upheap(size_ - 1);
    }

    int pop() {
        if (size_ == 0) {
            return -1;
        }
        // if (size_ == 1) {
        //     int element = heapqueue_.front();
        //     heapqueue_.pop_back();
        //     size_--;
        //     return element;
        // }
        int element = heapqueue_.front();
        std::swap(heapqueue_[0], heapqueue_[size_ - 1]);
        heapqueue_.pop_back();
        size_--;
        downheap(0);
        return element;
    }

    int top() { return heapqueue_.empty() ? -1 : heapqueue_.front(); }

    void heapify(const vector<int>& arr) {
        heapqueue_.clear();
        size_ = static_cast<int>(arr.size());
        heapqueue_.insert(heapqueue_.end(), arr.begin(), arr.end());
        for (int i = (size_ - 1) / 2; i >= 0; --i) {
            downheap(i);
        }
    }
};
