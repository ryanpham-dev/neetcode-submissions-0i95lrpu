
class Solution {
public:
     int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> maxStoneHeap{};
        for (const int weight : stones) {
            maxStoneHeap.push(weight);
        }
        while (maxStoneHeap.size() > 1) {
            int largest = maxStoneHeap.top();
            maxStoneHeap.pop();
            int secondLargest = maxStoneHeap.top();
            maxStoneHeap.pop();
            maxStoneHeap.push(std::abs(largest - secondLargest));
        }
        return maxStoneHeap.empty() ? 0 : maxStoneHeap.top();
    }
};