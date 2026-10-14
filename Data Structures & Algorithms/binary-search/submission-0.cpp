class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;

        while (r > l + 1) {
            int m = (l + r) / 2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l == -1 || nums[l] != target) return -1;
        return l;
    }
};
