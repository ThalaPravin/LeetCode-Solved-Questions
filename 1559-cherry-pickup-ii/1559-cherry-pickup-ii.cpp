class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m, vector<int>(m,-1)));
        return f(0,0,m-1,m,n,grid,dp);
    }

    int f(int i, int a, int b,int m, int n,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
     if(a<0 || a>=m || b<0 || b>=m) return -1e8;
      
    if(i==n-1){
        if(a==b) return grid[i][a];
        else{
            return grid[i][a] + grid[i] [b];
        }
    }
    
  
    
    if (dp[i][a][b]!=-1) return dp[i][a][b];
    
    int mx=-1e7;
    int val=0;
    
    for(int j1=-1; j1<=1; j1++){
        for(int j2=-1; j2<=1; j2++){
            if(a==b) val=grid[i][a];
            else val=grid[i][a] + grid[i][b];
            
            val+= f(i+1, a+j1 , b+j2 ,m,n, grid,dp);
            mx= max(mx, val);
        }
    }
    
    return dp[i][a][b]= mx;
}

};