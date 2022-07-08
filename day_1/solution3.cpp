#include <iostream>
#include <vector>

class Solution {
private:
    static void markIslandFrom(std::vector<std::vector<char>>& grid, int x, int y) {
        if ((x >= 0 && x < grid.size())
            && (y >= 0 && y < grid[x].size())
            && grid[x][y] == '1') {

            grid[x][y] = '*';

            markIslandFrom(grid, x + 1, y);
            markIslandFrom(grid, x, y + 1);
            markIslandFrom(grid, x - 1, y);
            markIslandFrom(grid, x, y - 1);
        }
    }

public:
    static int numIslands(std::vector<std::vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    markIslandFrom(grid, i, j);
                }
            }
        }
        return res;
    }
};

/**
 * @arg
 * n - height
 * m - width
 * grid: 1 - land, 0 - sea
 *
 * @example
 * input:
 * 4 5
 * 1 0 0 1 0
 * 1 0 0 0 0
 * 0 1 1 1 0
 * 1 1 0 1 1
 *
 * output:
 * 3
 */

int main() {
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> grid(n);
    for (size_t i = 0; i < n; i++) {
        grid[i].resize(m);
        for (size_t j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::cout << Solution::numIslands(grid);
    return 0;
}