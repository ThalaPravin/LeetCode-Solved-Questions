class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mp; 
        int l = 0, r = 0; 
        int count = 0;    
        
        while (r < s.length()) {
            char ch = s[r]; 
            mp[ch]++; 
            while (mp.size() == 3 && l <= r) {
                count += s.length() - r;  

                char leftChar = s[l]; 
                mp[leftChar]--;  

                if (mp[leftChar] == 0) {
                    mp.erase(leftChar);
                }
                
                l++; 
            }
            
            r++;  // Move the right pointer to expand the window
        }
        
        return count;  // Return the total count of valid substrings
    }
};
