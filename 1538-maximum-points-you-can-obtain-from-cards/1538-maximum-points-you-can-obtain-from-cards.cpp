class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0, r=0, mxsum=0,rind=cardPoints.size()-1;
        
        for(int i=0; i<k; i++){
            l+=cardPoints[i];
            mxsum=l;
        }


        for(int i=k-1; i>=0; i--){
            l-=cardPoints[i];
            r+=cardPoints[rind];
            rind--;
            mxsum=max(mxsum, l+r);
        }

        return mxsum;
    }
};