class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=0;i<numRows; i++){
            vector<int>temp(i+1);
            for(int j=0;j<=i; j++){
                if(j==0 || j==i) temp[j]=1;
                else{
                    temp[j]=ans[i-1] [j-1] + ans[i-1] [j];
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};