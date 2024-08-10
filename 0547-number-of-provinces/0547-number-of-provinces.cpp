class Solution {
public:
    void dfs(int start, vector<int>& vis, vector<vector<int>>& adj) {
        for(auto it: adj[start]) {
            if(!vis[it]) {
                vis[it] = 1;
                dfs(it, vis, adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int> vis(size, 0); 
        vector<vector<int>> adj(size);  

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int c = 0;

 
        for(int i = 0; i < size; i++) {
            if(!vis[i]) {
                vis[i] = 1;
                dfs(i, vis, adj);
                c++;
            }
        }

        return c;
    }
};