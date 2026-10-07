class Solution {
public:
    bool isPalindrome(string s) {
        string testStr = "";
        for (char ch: s) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) testStr += tolower(ch);
        }

        cout << testStr << "\n";

        int len = testStr.length();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (testStr[i] != testStr[j]) return false;
        }
        return true;
    }
};
