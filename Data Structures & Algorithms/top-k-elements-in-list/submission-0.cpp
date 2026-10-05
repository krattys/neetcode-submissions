class Solution {
public:
    const int MAXNUMS = 2001;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(MAXNUMS);
        for (int i: nums) {
            freq[i + 1000]++;
        }
        vector<pair<int, int>> numFreq;
        for (int i = 0; i < MAXNUMS; i++) {
            if (freq[i]) {
                numFreq.push_back({i - 1000, freq[i]});
            }
        }
        sort(numFreq.begin(), numFreq.end(), [](auto &l, auto &r) {
            return l.second > r.second;
        });

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(numFreq[i].first);
        }
        return res;
    }
};
