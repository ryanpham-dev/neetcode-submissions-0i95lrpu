class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return; 
        int low {}, mid{}, high = nums.size() - 1;
        while (mid <= high) {
            switch (nums.at(mid)) {
                case 0:
                std::swap(nums.at(low), nums.at(mid));
                low++;
                mid++;
                break;
                case 1:
                mid++;
                break;
                case 2:
                std::swap(nums.at(mid), nums.at(high));
                high--;
                break;
            }
            
        }
    }
};