class Solution {
public:

    int bfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        visited[row][col] = true;

        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int drow = -1; drow <= 1; drow++) {
                for (int dcol = -1; dcol <= 1; dcol++) {
                    if (drow != 0 && dcol != 0) continue;
                    int nrow = drow + row;
                    int ncol = dcol + col;
                    if (!(nrow >= 0) || !(nrow < n) || !(ncol >= 0) || !(ncol < m) || grid[nrow][ncol] == 0) {
                        ans++;
                    } 
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return ans;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    return bfs(i, j, visited, grid);
                }
            }
        }
        return 0;


        
    }
};