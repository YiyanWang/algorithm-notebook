#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories;

        int start = 0;
        int length = 0;
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (length > 0) {
                    string directory = path.substr(start, length + 1);
                    if (directory == "/..") {
                        if (directories.size() > 0) {
                            directories.pop_back();
                        }
                    } else if (directory != "/.") {
                        directories.push_back(directory);
                    }
                }
                start = i;
                length = 0;
            } else {
                length++;
            }
        }

        if (directories.size() == 0) {
            return "/";
        }

        string ans;
        for (int i = 0; i < directories.size(); i++) {
            ans += directories[i];
        }
        return ans;
    }
};