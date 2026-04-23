
#include <ranges>
class DisjointSets {
    std::vector<int> parent{};
    std::vector<int> rank{};
    int connectedComponents{};

public:
    explicit DisjointSets(int size) : parent(size), rank(size, 0), connectedComponents(size) {
        std::ranges::iota(parent, 0);
    }

    int find(int val) {
        if (parent[val] != val) {
            parent[val] = find(parent[val]);
        }
        return parent[val];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }

        // Attach the shorter tree under the taller one.
        if (rank[rootX] < rank[rootY]) {
            std::swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        if (rank[rootX] == rank[rootY]) {
            ++rank[rootX];
        }
        connectedComponents--;
        return true;
    }

    bool isConnected(int first, int second) { return find(first) == find(second); }

    [[nodiscard]] int getNumComponents() const { return connectedComponents; }
};

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        DisjointSets dset(static_cast<int>(isConnected.size()));
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected[i].size(); ++j) {
                if (isConnected[i][j] == 1) {
                    dset.unite(i, j);
                }
            }
        }

        return dset.getNumComponents();
    }
};