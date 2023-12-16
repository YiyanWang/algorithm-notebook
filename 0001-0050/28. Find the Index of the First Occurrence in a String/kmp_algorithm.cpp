#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> next = computeNext(needle);

        for (int i = 0, j = 0; i < n;) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }

            if (j == m) {
                return i - j;
            }
        }

        return -1;
    }

    vector<int> computeNext(string needle) {
        int m = needle.size();
        vector<int> next(m, 0);

        int len = 0;
        for (int i = 1; i < m;) {
            if (needle[len] == needle[i]) {
                next[i++] = ++len;
            } else if (len > 0) {
                len = next[len - 1];
            } else {
                i++;
            }
        }

        return next;
    }
};