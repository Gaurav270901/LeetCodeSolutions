#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool helper(const string& str, int left, int right) {
        if (left >= right) return true;

        if (str[left] != str[right]) return false;

        return helper(str, left + 1, right - 1);
    }

    bool isPalindrome(string input) {
        string cleaned;

        for (char c : input) {
            if (isalnum(static_cast<unsigned char>(c))) {
                cleaned += tolower(static_cast<unsigned char>(c));
            }
        }

        return helper(cleaned, 0, cleaned.size() - 1);
    }
};
