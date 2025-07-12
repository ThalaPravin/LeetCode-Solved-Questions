class Solution {
public:
    int res=-1;
    void dfs (int u, vector<int>&edges, vector<bool>&vis, vector<bool>&pathvis, vector<int>&count){
        vis[u]= true;
        pathvis[u]= true;
        int v =edges[u];
        

        if(v!=-1 && !vis[v]){
            count [v]= count[u]+1;
            dfs(v,edges, vis, pathvis, count);
        }
        else if(v!=-1 && pathvis[v]){
            res= max(res, count[u]- count[v]+1);
        }
        pathvis[u]= false;

        return ;
    }


    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        vector<bool>vis(n,false);   
        vector<bool>pathvis(n,false);
        vector<int>count(n, 1);

        for(int i=0; i<n; i++){
            if(!vis[i] && edges[i]!=-1){
                dfs(i,edges, vis, pathvis, count);
            }
        }

        return res;

    }

};