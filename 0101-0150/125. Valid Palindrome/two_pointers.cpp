#include <string>
using namespace std;

// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    static const char nonAlphanumeric = ' ';

    bool isPalindrome(string s) {
        char l, r;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < s.size() && (l = toAlphanumeric(s[i])) == nonAlphanumeric) {
                i++;
            }
            while (j >= 0 && (r = toAlphanumeric(s[j])) == nonAlphanumeric) {
                j--;
            }

            if (l != r) {
                return false;
            }
        }

        return true;
    }

    char toAlphanumeric(char c) {
        if (c >= 'a' && c <= 'z') {
            return c;
        } else if (c >= 'A' && c <= 'Z') {
            return tolower(c);
        } else if (c >= '0' && c <= '9') {
            return c;
        } else {
            return nonAlphanumeric;
        }
    }
};