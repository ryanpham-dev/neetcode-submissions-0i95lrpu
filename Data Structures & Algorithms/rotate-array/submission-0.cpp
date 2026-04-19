class Solution {
public:
void rotate(std::vector<int>& v, int k) {
    if (k == 0) {
        return;
    }

    int size = (int) v.size();
    k %= size;
    int rotations = std::gcd(size, k);
    for (int i = 0; i < rotations; ++i) {
        int temp = v[i];
        int j = i + k;
        while (j != i) {
            // int to = v[j];
            // v[j] = temp;
            // temp = to;
            std::swap(temp, v[j]);
            j = (j + k) % size;
        }
        v[i] = temp;
    }
}
};