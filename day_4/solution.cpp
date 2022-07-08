#include <vector>
#include "iostream"

class Solution {
public:
    static bool isInterleave(const std::string & s1, const std::string & s2, const std::string & s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        int prefix_s2 = common_prefix(s2, s3), prefix_s1 = common_prefix(s1, s3);

        std::vector<bool> d(s2.length() + 1);
        std::fill(d.begin(), d.begin() + prefix_s2 + 1, true);
        std::fill(d.begin() + prefix_s2 + 1, d.end(), false);

        std::vector<bool> d_next(s2.length() + 1);

        for (int i = 0; i < s1.length(); i++) {
            d_next[0] = (prefix_s1 > i);
            for (int j = 1; j < s2.length() + 1; j++) {
                if ((d[j] && s1[i] == s3[i + j]) || (d_next[j - 1] && s2[j - 1] == s3[i + j])) {
                    d_next[j] = true;
                } else {
                    d_next[j] = false;
                }
            }
            std::swap(d_next, d);
        }

        return d[s2.length()];
    }

private:
    static int common_prefix(const std::string & s1, const std::string & s2) {
        int prefix = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i]) {
                prefix = i + 1;
            } else {
                break;
            }
        }
        return prefix;
    }
};

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;
    std::cout << (Solution::isInterleave(s1, s2, s3) ? "true" : "false");
    return 0;
}
