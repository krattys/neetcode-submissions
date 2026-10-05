class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string st = strs[i];
            sort(st.begin(), st.end());
            mp[st].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto [key, value]: mp) {
            res.push_back(value);
        }

        return res;
    }
};
