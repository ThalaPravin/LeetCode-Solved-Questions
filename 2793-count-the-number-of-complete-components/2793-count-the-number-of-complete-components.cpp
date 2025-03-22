#include <bits/stdc++.h>
// #define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
#define test int thala;cin>>thala;while(thala--)
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<set<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        vector<int> v(n);
        int z = 0;
        function<void(int, vector<int>&)> dfs = [&](int x, vector<int>& a) {
            v[x] = 1;
            a.push_back(x);
            for (int y : g[x]) if (!v[y]) dfs(y, a);
        };
        for (int i = 0; i < n; i++) if (!v[i]) {
            vector<int> a;
            dfs(i, a);
            int m = a.size();
            bool f = 1;
            for (int x : a) if (g[x].size() != m - 1) f = 0;
            z += f;
        }
        return z;
    }
};
