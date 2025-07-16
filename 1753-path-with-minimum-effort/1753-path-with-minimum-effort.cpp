class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if (n==1 && m==1) return 0;
        vector<vector<int>>distance(n+1,vector<int>(m+1,INT_MAX));
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        vector<int>dx{0,0,1,-1};
        vector<int>dy{-1,1,0,0};

        int ans=INT_MAX;
    
        while(!pq.empty()){
            auto it = pq.top();
            int dis= it.first;
            int row= it.second.first;
            int col = it.second.second;
            pq.pop();
           

            for(int i=0; i<4; i++){
                int newr= dx[i] +row;
                int newc = dy[i]+col;

                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int neweff = max(dis, abs(heights[row][col]- heights[newr][newc]));

                    if(neweff < distance [newr][newc]){
                        distance[newr][newc]= neweff;
                        pq.push({neweff,{newr,newc}});
                    }
                }
            }
        }

        return distance[n-1] [m-1];
      
    }
};