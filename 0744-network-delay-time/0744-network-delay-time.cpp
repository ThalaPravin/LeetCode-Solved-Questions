class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
   
        vector<pair<int, int>> adj[n + 1];
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for (auto& [nei, wt] : adj[node]) {
                if (time + wt < dist[nei]) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
