class Solution {
public:

    const char DELIM = '-';
    string encode(vector<string>& strs) {
        string res = "";
        for (string st: strs) {
            int len = st.length();
            res += to_string(len) + DELIM + st;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int len = s.length();
        int i = 0;
        while (i < len) {
            string strLen = "";
            int j;
            for (j = i; s[j] != DELIM; j++) {
                strLen += s[j];
            }
            int toCatch = stoi(strLen);
            j++;
            res.push_back(s.substr(j, toCatch));
            i = j + toCatch;
        }
        return res;
    }
};