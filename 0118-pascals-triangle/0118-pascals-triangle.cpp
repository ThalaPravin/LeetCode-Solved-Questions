class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n=numRows;   
        vector<int>dum;
        dum.push_back(1);
        ans.push_back(dum);

        for(int i=1; i<n; i++){
            vector<int>cur(i+1,0);
            cur[0]=1;
            cur[i]=1;
            for(int j=1; j<i; j++ ){
                cur[j]= ans[i-1][j-1] + ans[i-1] [j];
            }
            ans.push_back(cur);
        }

        return ans;
    }
};