#include <bits/stdc++.h>
// #define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
#define test int thala; cin >> thala; while (thala--)

class Solution {
public:
    

    string stringHash(string s, int k) {
        int n = s.length(), d = n / k, di = 0;
        string r = "";
        
        for (int i = 0; i < n; i += k) {
            int sum = 0;
            di++;
            for (int j = 0; j < k; j++) {
                sum += s[i + j] - 'a';
                di=0;
            }
            r += (sum % 26) + 'a';
        }
        
        return r;
    }
};
