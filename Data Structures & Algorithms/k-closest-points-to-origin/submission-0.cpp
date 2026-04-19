class Solution {
public:
    vector<vector<int>> kClosest(const vector<vector<int>>& points, unsigned threshold) {
        std::priority_queue<pair<int, pair<int, int>>> maxHeap{};
        for (const auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.emplace(dist, std::make_pair(point[0], point[1]));
            if (maxHeap.size() > threshold) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> output;
        output.reserve(maxHeap.size());
        while (!maxHeap.empty()) {
            vector<int> point{maxHeap.top().second.first, maxHeap.top().second.second};
            output.emplace_back(point);
            maxHeap.pop();
        }
        return output;
    }
};