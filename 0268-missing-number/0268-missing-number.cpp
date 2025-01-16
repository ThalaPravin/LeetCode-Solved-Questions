class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]!=i) return i;
        }
        return n;
    }
};