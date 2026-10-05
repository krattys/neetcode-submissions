class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> schars(26), tchars(26);
        for (char ch: s) {
            int index = ch - 'a';
            schars[index]++;
        }

        for (char ch: t) {
            int index = ch - 'a';
            tchars[index]++;
        }

        for (int i = 0; i < 26; i++) {
            if (schars[i] != tchars[i]) {
                return false;
            }
        }

        return true;
    }
};
