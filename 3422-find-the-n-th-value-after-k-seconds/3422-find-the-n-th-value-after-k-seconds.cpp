class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
          // int arr[n]={1};
        vector<long long > arr(n, 1);
        const unsigned int M =1e9 +7;

        for(int j=0; j<k; j++){
             for(int i=0 ; i<n-1; i++){
            arr[i+1]=(arr[i]+arr[i+1])%M;
        }
        }
       
        
        return arr[n-1];
    }
};