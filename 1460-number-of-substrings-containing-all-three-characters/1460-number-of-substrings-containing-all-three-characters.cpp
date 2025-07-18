class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0, n= s.size(), l=0, r=0;
        map<char,int>mp;
        while(r<n){
            mp[s[r]]++;

            while(mp.size()== 3 && l<=r){
                cnt+= n-r;
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
        }

        return cnt;
    }
};
