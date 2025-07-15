class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>distance(n+1,vector<int>(m+1,INT_MAX));
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        priority_queue<
        pair<pair<int, int>, pair<int, int>>, 
        vector<pair<pair<int, int>, pair<int, int>>>, 
        greater<pair<pair<int, int>, pair<int, int>>>>pq;
        pq.push(make_pair(make_pair(0,heights[0][0]), make_pair(0,0)));
        vector<int>dx{0,0,1,-1};
        vector<int>dy{-1,1,0,0};
        while(pq.size()!=0){
            int current_cell_value=pq.top().first.second;
            int current_mx=pq.top().first.first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            vis[row][col]=1;
            pq.pop();
            if(row==n-1 && col==m-1){
                return current_mx;
            }
            for(int i=0;i<4;i++){
                if(row+dx[i]>=0 && row+dx[i]<n && col+dy[i]>=0 && col+dy[i]<m ){
                    int next_row=row+dx[i];
                    int next_col=col+dy[i];
                    int next_cell_value=heights[next_row][next_col];
                    if(abs(current_cell_value-next_cell_value)<distance[next_row][next_col]){
                        distance[next_row][next_col]=abs(current_cell_value-next_cell_value);
                        pq.push(make_pair(make_pair(max(current_mx,distance[next_row][next_col]), heights[next_row][next_col]), make_pair(next_row,next_col)));
                    }
                }
            }
        }
        return 0;
    }
};