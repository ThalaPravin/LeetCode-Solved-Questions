class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0, r=0, mxp=0,curr=0;

        for(int i=0; i<k; i++){
            curr+=cardPoints[i];
        }
        l=k-1;
        mxp=curr;

        for(int i=n-1; i>=n-k; i--){
            curr+=cardPoints[i];
            curr-= cardPoints[l];
            l--;
            mxp=max(mxp, curr);
        }
        
        return mxp;
    }
};