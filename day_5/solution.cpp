#include <iostream>

class Solution {
public:
    static int numSteps(const std::string &s) {
        int i = s.length() - 1;
        int res = 0;

        bool first_ones = true;
        while (i >= 0) {
            int block_size = 0;
            while (i >= 0 && s[i] == '0') {
                block_size++;
                i--;
            }
            if (first_ones) {
                res += block_size;
            } else {
                res += (block_size - 1) * 2;
            }

            block_size = 0;
            while (i >= 0 && s[i] == '1') {
                block_size++;
                i--;
            }

            if (first_ones) {
                if (block_size == 1 && i < 0) {
                    return res;
                }

                res += block_size + 1;
                first_ones = false;
            } else {
                res += block_size + 2;
            }
        }

        return res;
    }
};

int main() {
    std::string s;
    std::cin >> s;
    std::cout << Solution::numSteps(s);
    return 0;
}



