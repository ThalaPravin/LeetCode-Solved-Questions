class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToIndex;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToIndex.count(email)) {
                    ds.unionBySize(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }

        vector<string> mergedEmails[n];
        for (auto &[email, idx] : emailToIndex) {
            int parent = ds.findUPar(idx);
            mergedEmails[parent].push_back(email);
        }

        vector<vector<string>> result;
        for (int i = 0; i < n; ++i) {
            if (mergedEmails[i].empty()) continue;
            sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), mergedEmails[i].begin(), mergedEmails[i].end());
            result.push_back(temp);
        }

        return result;
    }
};