#include <numeric>
#include <vector>
class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
    int connectedComponents;

public:
    explicit UnionFind(int size) : parent(size), rank(size, 0), connectedComponents(size) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int val) {
        if (parent[val] != val) {
            parent[val] = find(parent[val]);
        }
        return parent[val];
    }

    bool _union(int x, int y) {
        int rank_x = find(x);
        int rank_y = find(y);

        if (rank_x == rank_y) {
            return false;
        }

        if (rank_x > rank_y) {
            parent[rank_y] = rank_x;
        } else if (rank_y > rank_x) {
            parent[rank_x] = rank_y;
        } else {
            parent[rank_x] = rank_y;
            rank_y++;
        }
        connectedComponents--;
        return true;
    }

    bool isSameComponent(int first, int second) { return find(first) == find(second); }

    int getNumComponents() { return connectedComponents; }
};