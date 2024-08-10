class Solution {
public:

    void bfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int color, int inicolor){
        ans[row][col] = color;
        int n = ans.size();
        int m = ans[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

       
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && ans[nrow][ncol] == inicolor) {
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int inicolor = image[sr][sc];

        
        if (inicolor == color) return image;

        bfs(sr, sc, image, ans, color, inicolor);

        return ans;
    }
};