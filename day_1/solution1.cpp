#include <iostream>
#include <vector>

class Solution {
public:
    static void reverseString(std::vector<char> & s) {
        for (int i = 0; i < s.size() / 2; i++) {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }
};

/**
 * @example
 * input: Hello!
 * output: !olleH
 */

int main() {
    std::string s;
    std::cin >> s;

    std::vector<char> vec_s(s.begin(), s.end());

    Solution::reverseString(vec_s);

    std::cout << std::string(vec_s.begin(), vec_s.end());
    return 0;
}
