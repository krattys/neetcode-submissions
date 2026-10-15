class Solution {
public:
    int isTargetPresent(vector<int> &nums, int target, int l, int r) {
        auto it = lower_bound(nums.begin() + l, nums.begin() + r, target);
        if (it != nums.begin() + r && *it == target) return it - nums.begin();
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] == target) return 0;
            return -1;
        }

        if (nums[0] < nums[n - 1]) {
            cout << n << "\n";
            return isTargetPresent(nums, target, 0, n);
        }
        int l = 0, r = n - 1;
        while (r > l) {
            int m = l + (r - l + 1) / 2;
            cout << l << " " << m << " " << r << "\n";
            if (m == n - 1) {
                if (nums[m] == target) return m;
                return isTargetPresent(nums, target, 0, m);
            }

            if (nums[m] < nums[m + 1] && nums[m] < nums[m - 1]) {
                int leftRes = isTargetPresent(nums, target, 0, m);
                int rightRes = isTargetPresent(nums, target, m, n);
                if (leftRes != -1) return leftRes;
                return rightRes;
            }

            if (nums[m] < nums[0]) {
                r = m;
            } else if (nums[m] > nums[0]) {
                l = m;
            }
        }

        return -1;
    }
};
