class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        for (const auto& row : grid) {
            for (int val : row) {
                values.push_back(val);
            }
        }

        sort(values.begin(), values.end());

        for (int val : values) {
            if (abs(val - values[0]) % x != 0) {
                return -1;
            }
        }

        int median = values[values.size() / 2];
        int operations = 0;

        for (int val : values) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};