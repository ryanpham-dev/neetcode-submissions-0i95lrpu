class DisjointSetsUnion {
private:
    std::vector<int> parent_;
    std::vector<int> rank_;
    int connectedComponents_{};

public:
    DisjointSetsUnion() = default;

    explicit DisjointSetsUnion(int size) : parent_(size), rank_(size), connectedComponents_(size) {
        std::iota(parent_.begin(), parent_.end(), 0);
    }

    int find(int value) {
        if (parent_[value] != value) {
            parent_[value] = find(parent_[value]);  // path compression
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
    int minimumSpanningTree(std::vector<std::vector<int>>& edges, int n) {
        DisjointSetsUnion dsu{n};
        std::sort(edges.begin(), edges.end(),
                  [](const auto& lhs, const auto& rhs) { return lhs[2] < rhs[2]; });
        int totalWeight{};
        for (const auto& edge : edges) {
            if (dsu.unite(edge[0], edge[1])) {
                totalWeight += edge[2];
            }
            if (dsu.getConnectedComponents() == 1) {
                break;
            }
        }
        return dsu.getConnectedComponents() == 1 ? totalWeight : -1;
    }
};