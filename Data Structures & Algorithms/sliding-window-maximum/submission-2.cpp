class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        int l = 0;
        vector<int> res;
        for (int r = 0; r < n; r++) {
            while (!dq.empty() && nums[dq.front()] < nums[r]) {
                dq.pop_front();
            }
            dq.push_front(r);
            while (l > dq.back()) {
                dq.pop_back();
            }

            if (r + 1 >= k) {
                res.push_back(nums[dq.back()]);
                l++;
            }
        }

        return res;
    }
};
