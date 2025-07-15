class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            int d = grid[i][j];
            if (i == n - 1 && j == n - 1) return d;
            int xlen = min(n , i + 2), ylen = min(n , j + 2);
            for(int x = max(0 , i - 1); x < xlen; ++x){
                for(int y = max(0 , j - 1); y < ylen; ++y){
                    if(!grid[x][y]){
                        grid[x][y] = d + 1;
                        q.push({x , y});
                    }
                }
            }
        }
        return -1;
    }
};