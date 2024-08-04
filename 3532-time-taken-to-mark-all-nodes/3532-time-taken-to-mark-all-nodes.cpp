class Solution {
public:
    void dfs1(int u, int p, vector<vector<int>>&g,
                    vector<int>&f, vector<int>&s) {
        for(auto v: g[u]) if(v!=p) {
            dfs1(v, u, g,f,s);
            if(f[v]+(v%2==0?2:1) > f[u]) {
                s[u]=f[u];
                f[u]=f[v]+(v%2==0?2:1);
            } else if(f[v]+(v%2==0?2:1) > s[u]) {
                s[u]=f[v]+(v%2==0?2:1);
            }
        }
    }
    void findMax(int u, int p, int to, vector<vector<int>>&g,
                    vector<int>&f, vector<int>&s,vector<int>&ans) {
        ans[u]=max(f[u],to);
        for(auto v: g[u])if(v!=p) {
            if(f[v]+(v%2==0?2:1)==f[u]) {
                findMax(v,u,max(to, s[u])+(u%2==0?2:1),g,f,s,ans);
            } else {
                findMax(v,u,ans[u]+(u%2==0?2:1),g,f,s,ans);
            }
        }
    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size();
        n++;
        vector<vector<int>> g(n);

        for(auto x: edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        vector<int> f(n), s(n);
        dfs1(0, -1,g,f,s);
        vector<int> ans(n);
        findMax(0,-1,0,g,f,s,ans);


        return ans;
    }
};