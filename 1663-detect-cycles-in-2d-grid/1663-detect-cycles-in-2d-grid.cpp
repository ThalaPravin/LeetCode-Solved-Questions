class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();             
        int n = grid[0].size();          
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (!vis[i][j]) {
                    char target = grid[i][j];
                    queue<pair<pair<int, int>, pair<int, int>>> q;
                    q.push({{i, j}, {i, j}}); 
                    vis[i][j] = 1;        
                    while (!q.empty()) {
                        int r = q.front().first.first;     
                        int c = q.front().first.second;    
                        int pr = q.front().second.first;   
                        int pc = q.front().second.second; 
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k]; 
                            int nc = c + dc[k]; 
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == target) {
                                if (!vis[nr][nc]) {
                
                                    vis[nr][nc] = 1;
                                    q.push({{nr, nc}, {r, c}});
                                } else if (nr != pr || nc != pc) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};