
class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        std::make_heap(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i) {
            std::pop_heap(gifts.begin(), gifts.end());
            int largest = gifts.back();
            gifts.pop_back();
            largest = static_cast<int>(std::sqrt(largest));
            gifts.emplace_back(largest);
            std::push_heap(gifts.begin(), gifts.end());
        }

        long long result = std::accumulate(gifts.begin(), gifts.end(), 0ll);
        return result;
    }
};