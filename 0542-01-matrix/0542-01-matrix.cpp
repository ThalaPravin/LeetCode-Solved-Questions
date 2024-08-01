class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();

        vector<vector<int>>dist(n, vector<int>(m,0));
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>>q;
        int stps=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    dist[i][j]=1;
                }
            }
        }

        int drow[]={0,-1,1,0};
        int dcol[]= {1,0,0,-1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            stps=q.front().second;
            q.pop();
            dist[row][col]=stps;

            for(int i=0; i<4; i++){
                int nrow= row+ drow[i];
                int ncol= col+ dcol[i];

                if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && mat[nrow][ncol]==1 ){
                    q.push({{nrow, ncol}, stps+1});
                    vis[nrow][ncol]=1;
                }
            }
        }

        return dist;
        
    }
};