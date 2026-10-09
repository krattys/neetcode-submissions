class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int n = s.length();
        int l = 0;
        int res = 0;
        for (int r = 0; r < n; r++) {
            if (us.find(s[r]) != us.end()) {
                res = max(res, (int)us.size());
                while (s[l] != s[r]) {
                    us.erase(s[l]);
                    l++;
                }
                l++;
            }
            us.insert(s[r]);
        }

        res = max(res, (int)us.size());
        return res;
    }
};
