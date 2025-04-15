class Solution {
public:
    vector<vector<int>> build_graph(const vector<vector<int>>& p, int k) {
        int n = p.size();
        vector<vector<int>> adj_list(n);
        vector<unordered_set<int>> s(n);
        
      
        for (int i = 0; i < n; i++) {
            for (auto &x: p[i])
                s[i].insert(x);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int common = 0;
                for (auto &x: s[j]) {
                    if (s[i].count(x)) common++;
                    if (common >= k) break;
                }
                if (common >= k) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        return adj_list;
    }
    
    void dfs(int node, const vector<vector<int>>& adj_list, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neigh: adj_list[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adj_list, visited);
            }
        }
    }
    
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        vector<vector<int>> adj = build_graph(properties, k);
        int n = properties.size();
        vector<bool> visited(n, false);
       
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};