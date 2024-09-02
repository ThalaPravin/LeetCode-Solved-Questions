

class Solution {
public:
      int minFlips(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int res = 0;

        if (n % 2 == 1 && m % 2 == 1) {
            if (g[n / 2][m / 2] == 1) {
                res += 1;
            }
        }

        vector<int> cnt(3, 0);
        if (n % 2 == 1) {
            int l = 0, r = m - 1;
            while (l < r) {
                int sm = g[n / 2][l] + g[n / 2][r];
                cnt[sm] += 1;
                l += 1;
                r -= 1;
            }
        }

        if (m % 2 == 1) {
            int l = 0, r = n - 1;
            while (l < r) {
                int sm = g[l][m / 2] + g[r][m / 2];
                cnt[sm] += 1;
                l += 1;
                r -= 1;
            }
        }

        if (cnt[2] % 2 == 1) {
            if (cnt[1] > 0) {
                res += cnt[1];
            } else {
                res += 2;
            }
        } else {
            res += cnt[1];
        }

        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                int a = g[i][j];
                int b = g[n - 1 - i][j];
                int c = g[i][m - 1 - j];
                int d = g[n - 1 - i][m - 1 - j];

                int sm = a + b + c + d;

                if (sm != 0 && sm != 4) {
                    res += min(sm, 4 - sm);
                }
            }
        }

        return res;
    }
};
