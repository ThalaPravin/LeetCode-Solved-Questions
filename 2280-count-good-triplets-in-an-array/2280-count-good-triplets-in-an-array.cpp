class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);

        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i;
        }

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = pos[nums1[i]];
        }

        vector<long long> left(n, 0), right(n, 0);
        vector<int> bit(n + 2, 0);

        for (int i = 0; i < n; ++i) {
            left[i] = query(bit, mapped[i]);
            update(bit, mapped[i] + 1, 1);
        }

        fill(bit.begin(), bit.end(), 0);

        for (int i = n - 1; i >= 0; --i) {
            right[i] = query(bit, n) - query(bit, mapped[i] + 1);
            update(bit, mapped[i] + 1, 1);
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += left[i] * right[i];
        }
        return res;
    }

    void update(vector<int>& bit, int i, int val) {
        while (i < bit.size()) {
            bit[i] += val;
            i += i & -i; 
        }
    }

    int query(vector<int>& bit, int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i; 
        }
        return res;
    }
};