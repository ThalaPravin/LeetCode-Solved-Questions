class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       int l = 0, r = 0, maxlen = 0;
       map<char, int> mp;
       
       while (r < n) {
            
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;  
            }

            mp[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
       }

       return maxlen;
    }
};