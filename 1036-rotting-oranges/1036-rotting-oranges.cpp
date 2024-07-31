#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        std::queue<std::pair<std::pair<int, int>, int>> q;

        // Mark all rotten oranges in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int t = 0;
        int drow[] = {0, -1, 1, 0};
        int dcol[] = {-1, 0, 0, 1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int ct = q.front().second;
            t = std::max(t, ct);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, ct + 1});
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return t;
    }
};
