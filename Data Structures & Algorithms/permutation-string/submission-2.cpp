class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        if (len1 > len2) return false;
        vector<int> count1(26), count2(26);
        for (int i = 0; i < len1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) matches += (count1[i] == count2[i]);

        int l = 0;
        for (int r = len1; r < len2; r++) {
            if (matches == 26) return true;
            int index = s2[r] - 'a';
            count2[index]++;
            if (count1[index] == count2[index]) {
                matches++;
            } else if (count1[index] + 1 == count2[index]) {
                matches--;
            }

            index = s2[l] - 'a';
            count2[index]--;
            if (count1[index] == count2[index]) {
                matches++;
            } else if (count1[index] - 1 == count2[index]) {
                matches--;
            }
            l++;
        }

        return matches == 26;
    }
};
