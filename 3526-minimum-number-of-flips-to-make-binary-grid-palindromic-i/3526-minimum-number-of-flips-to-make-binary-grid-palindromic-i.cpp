class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minRowFlips = 0, minColFlips = 0;

        for (int i = 0; i < m; ++i) {
            int rowFlips = 0;
            for (int j = 0; j < n / 2; ++j) {
                if (grid[i][j] != grid[i][n - j - 1]) {
                    rowFlips++;
                }
            }
            minRowFlips += rowFlips;
        }

        for (int j = 0; j < n; ++j) {
            int colFlips = 0;
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][j] != grid[m - i - 1][j]) {
                    colFlips++;
                }
            }
            minColFlips += colFlips;
        }

        return min(minRowFlips, minColFlips);
    }
};
