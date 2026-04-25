class DisjointSetsUnion {
    std::vector<int> parent_;
    std::vector<int> rank_;
    int connectedComponents_;

public:
    explicit DisjointSetsUnion(int size) : parent_(size), rank_(size), connectedComponents_(size) {
        std::iota(parent_.begin(), parent_.end(), 0);
    }

    int find(int value) {
        if (parent_[value] != value) {
            parent_[value] = find(parent_[value]);
        }
        return parent_[value];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank_[rootX] < rank_[rootY]) {
                std::swap(rootX, rootY);
            }
            parent_[rootY] = rootX;
            if (rank_[rootX] == rank_[rootY]) {
                ++rank_[rootX];
            }
            connectedComponents_--;
            return true;
        }
        return false;
    }

    [[nodiscard]] int getConnectedComponents() const { return connectedComponents_; }
};
class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        auto manhattanDistance = [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
            return std::abs(lhs.front() - rhs.front()) + std::abs(lhs.back() - rhs.back());
        };
        std::vector<std::tuple<int, int, int>> distances;
        points.reserve((points.size() / 2) * (points.size() - 1));
        int size = static_cast<int>(points.size());
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                distances.emplace_back(manhattanDistance(points[i], points[j]), i, j);
            }
        }
        std::sort(distances.begin(), distances.end());
        DisjointSetsUnion dsu{static_cast<int>(points.size())};
        int totalWeight{};
        for (const auto& [weight, from, to] : distances) {
            if (dsu.unite(from, to)) {
                totalWeight += weight;
            }
            if (dsu.getConnectedComponents() == 1) {
                break;
            }
        }
        return totalWeight;
    }
};