class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        std::sort(intervals.begin(), intervals.end());

        auto currentStart {intervals.front().front()};
        auto currentEnd {intervals.front().back()};
        

        for (int i = 1; i < intervals.size(); ++i) {
            int start = intervals.at(i).front();
            int end = intervals.at(i).back();
            
            if (start <= currentEnd) {
                currentEnd = std::max(currentEnd, end);
            }
            else {
                output.push_back(vector<int> {currentStart, currentEnd});
                currentStart = start;
                currentEnd = end;
            }
        }
        output.push_back(std::vector<int> {currentStart, currentEnd});

        return output;
    }
};