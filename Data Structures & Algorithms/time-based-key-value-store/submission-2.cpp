class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store{};

public:
    TimeMap() = default;
    void set(std::string key, std::string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    std::string get(std::string key, int timestamp) {
        std::span times = store[key];
        auto iter =
            std::upper_bound(times.begin(), times.end(), timestamp,
                             [](auto target, auto& element) { return target < element.first; });
        if (iter != times.begin()) {
            return std::prev(iter)->second;
        }
        return {};
    }
};