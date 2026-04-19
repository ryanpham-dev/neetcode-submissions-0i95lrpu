
class Solution {
public:
     int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> maxStoneHeap{};
        for (const int weight : stones) {
            maxStoneHeap.emplace(weight);
        }
        while (maxStoneHeap.size() > 1) {
            int largest = maxStoneHeap.top();
            maxStoneHeap.pop();
            int secondLargest = maxStoneHeap.top();
            maxStoneHeap.pop();
            maxStoneHeap.emplace(std::abs(largest - secondLargest));
        }
        return maxStoneHeap.top();
    }
};