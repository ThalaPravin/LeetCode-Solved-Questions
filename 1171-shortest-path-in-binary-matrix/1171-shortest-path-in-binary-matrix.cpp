class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        vis[0][0] = 1;

        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto [x, y, dist] = q.front(); 
            q.pop();

            if (x == n - 1 && y == n - 1)
                return dist;

            for (int dir = 0; dir < 8; dir++) {
                int newr = x + dx[dir];
                int newc = y + dy[dir];

                if (newr >= 0 && newr < n && newc >= 0 && newc < n &&
                    grid[newr][newc] == 0 && vis[newr][newc] == 0) {
                    q.push({newr, newc, dist + 1});
                    vis[newr][newc] = 1;
                }
            }
        }

        return -1;
    }
};