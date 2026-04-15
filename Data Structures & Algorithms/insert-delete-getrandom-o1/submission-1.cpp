
class RandomizedSet {
private:
    std::vector<int> values{};
    std::unordered_map<int, unsigned long> record{};
    std::random_device dev;
    std::mt19937 rng{dev()};

public:
    bool insert(int val) {
        if (record.contains(val)) {
            return false;
        }
        values.emplace_back(val);
        record[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (record.contains(val)) {
            auto currentIndex = record[val];
            std::swap(values[currentIndex], values[values.size() - 1]);
            record[values[currentIndex]] = currentIndex;
            record.erase(val);
            values.pop_back();
            return true;
        }
        return false;
    }

    int getRandom() {
        std::uniform_int_distribution<int> dis(0, static_cast<int>(values.size()) - 1);
        auto randomIndex = dis(rng);
        return values[randomIndex];
    }
};
