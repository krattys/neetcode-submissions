class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 1 || nums[0] < nums[n - 1]) return nums[0];
        int l = 0, r = n - 1;
        while (r > l) {
            int m = l + (r - l + 1) / 2;
            if (m == n - 1 && nums[m] < nums[m - 1]) {
                return nums[m];
            }
            if (m == 0 && nums[m] < nums[m + 1]) {
                return nums[m];
            }
            if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1]) {
                return nums[m];
            }
            if (nums[m] > nums[0]) {
                l = m;
            } else if (nums[m] < nums[0]) {
                r = m;
            }
        }

        return nums[0];
    }
};
