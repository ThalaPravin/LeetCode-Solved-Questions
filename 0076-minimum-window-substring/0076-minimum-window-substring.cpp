class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, needCount = need.size();
        int l = 0, r = 0;
        int minLen = INT_MAX, minStart = 0;

        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            while (have == needCount) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }
                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
