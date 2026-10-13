class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) pq.push({nums[i], i});

        int n = nums.size(), l = 0;
        vector<int> res;
        for (int r = k; r < n; r++) {
            res.push_back(pq.top().first);
            while (!pq.empty() && pq.top().second <= l) {
                pq.pop();
            }
            pq.push({nums[r], r});
            l++;
        }
        res.push_back(pq.top().first);

        return res;
    }
};
