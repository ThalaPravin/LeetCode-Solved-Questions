class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int vis[n][m];

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int t = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int ct = q.front().second;
            t = max(t, ct);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, ct + 1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }

        return t;
    }
};