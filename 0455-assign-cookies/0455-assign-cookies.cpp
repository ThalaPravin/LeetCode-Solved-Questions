class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n=g.size();
       
        int ans=0;
        int i=0, j=0;
        int m=s.size();
        while(i<n&&j<m){
            if(g[i]<=s[j]){
                ans++;
                i++;
                j++;
            }
            else j++;
        }
        return ans;

        
    }
};