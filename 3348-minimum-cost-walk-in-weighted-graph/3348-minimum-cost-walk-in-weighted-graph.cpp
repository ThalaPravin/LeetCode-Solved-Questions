class Solution {
public:
    vector<int> parent, size;

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;

        if (size[pu] > size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }

    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, int& val) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (val == -1) {
                val = it.second;
            } else {
                val &= it.second;
            }
            if (!vis[it.first]) {
                dfs(it.first, adj, vis, val);
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
            Union(it[0], it[1]);
        }

        vector<int> vis(n, 0);
        vector<int> cost(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int val = -1;
                dfs(i, adj, vis, val);
                int pu = findParent(i);
                cost[pu] = val;
            }
        }

        vector<int> ans(query.size());
        for (int i = 0; i < query.size(); i++) {
            int u = query[i][0];
            int v = query[i][1];
            int pu = findParent(u);
            int pv = findParent(v);

            if (pu == pv) {
                ans[i] = cost[pu];
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};