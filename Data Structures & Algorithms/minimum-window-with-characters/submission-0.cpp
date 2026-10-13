class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.length();
        int lent = t.length();

        if (lens < lent) return "";

        unordered_map<char, int> counts, countt;
        for (char ch: t) {
            countt[ch]++;
        }
        int uniqueCharst = countt.size();

        int l = 0, res = lens + 1, uniqueCharss = 0;
        int finall = -1, finalr = -1;
        for (int r = 0; r < lens; r++) {
            counts[s[r]]++;
            if (counts[s[r]] == countt[s[r]]) uniqueCharss++;
            while (l <= r && counts[s[l]] - 1 >= countt[s[l]]) {
                counts[s[l]]--;
                l++;
            }
            if (uniqueCharss == uniqueCharst && r - l + 1 <= res) {
                res = min(res, r - l + 1);
                finall = l;
                finalr = r;
            }
        }

        if (finall == -1) return "";
        string ans = "";
        for (int i = finall; i <= finalr; i++) ans += s[i];
        return ans;
    }
};
