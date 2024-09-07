class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s, t,dp);
    }

    int f(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        if(j<0) return 1;

        if(i<0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int take=0;

        if(s[i]==t[j]){
            take=f(i-1,j-1,s,t,dp);
        }
        int nottake=f(i-1,j,s,t,dp);

        return dp[i][j]= take+nottake;
      }
};