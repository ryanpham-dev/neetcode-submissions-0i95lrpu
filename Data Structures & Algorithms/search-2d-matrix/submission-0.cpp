class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rols = matrix.size();
        int cols = matrix[0].size();
        int totals = rols * cols;
        int left = 0;
        int right = totals - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int rid = mid / cols;
            int cid = mid % cols;
            if (matrix[rid][cid] == target) {
                return true;
            }
            else if (target >matrix[rid][cid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return false;
    }
};
