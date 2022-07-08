#include <iostream>
#include <vector>

class Solution {
public:
    static int coinChange(const std::vector<int> & coins, int amount) {
        int max = 0;
        for (int coin : coins) {
            if (coin <= amount) {
                max = std::max(max, coin);
            }
        }

        std::vector<int> results(max + 1, -1);
        results[0] = 0;

        int head = 0;
        int cur_nominal = 0;

        while (cur_nominal < amount) {
            for (int coin : coins) {
                if (coin > amount) {
                    continue;
                }
                if (results[head] != -1
                    && cur_nominal <= amount - coin
                    && (results[(head + coin) % results.size()] == - 1
                        || results[(head + coin) % results.size()] > results[head] + 1)) {

                    results[(head + coin) % results.size()] = results[head] + 1;
                }
            }

            results[head] = -1;
            cur_nominal++;
            head = (head + 1) % results.size();
        }
        return results[head];
    }
};

/**
 * @arg
 * coins_size - quantity of coins
 * coins - array of coins
 * amount
 *
 * @example
 * input:
 * 3
 * 1 2 5
 * 11
 *
 * output:
 * 3
 */

int main() {
    size_t coins_size;
    std::cin >> coins_size;
    std::vector<int> coins(coins_size);
    for (int i = 0; i < coins_size; i++) {
        std::cin >> coins[i];
    }
    int amount;
    std::cin >> amount;

    std::cout << Solution::coinChange(coins, amount);
    return 0;
}