class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size();
        int tsum= n*(n+1)/2;
        int sum=0;

        for(int i:arr) sum+=i;

        return tsum-sum;
        
    }
};