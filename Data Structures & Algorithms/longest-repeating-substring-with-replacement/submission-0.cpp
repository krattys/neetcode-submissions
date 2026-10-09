class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int res = 1;

        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int l = 0, dist = 0, tmp = 1;
            for (int r = 0; r < len; r++) {
                if (s[r] != ch) dist++;
                if (dist > k) tmp = max(tmp, r - l);
                while (dist > k) {
                    if (s[l] != ch) dist--;
                    l++;
                }
            }
            tmp = max(tmp, len - l);
            res = max(res, tmp);
        }

        return res;
    }
};
