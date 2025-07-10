class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                }
            }
        }

        int rowarr[] = {-1, 0, 1, 0};
        int colarr[] = {0, -1, 0, 1};
        int tm = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + rowarr[i];
                int ncol = c + colarr[i];

                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n
                    && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 1) {
                    return -1;
                }
            }
        }

        return tm;
    }
};
