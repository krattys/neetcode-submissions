class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uos(nums.begin(), nums.end());
        int res = 0;

        for (int num: nums) {
            if (uos.find(num - 1) == uos.end()) {
                int len = 1;
                while (uos.find(num + len) != uos.end()) len++;
                res = max(res, len);
            }
        }

        return res;
    }
};
