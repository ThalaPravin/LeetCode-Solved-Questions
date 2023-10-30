class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        // int count;
        for(int i=0; i<=n; i++){
            int count=0;
            int num=i;
            while(num){
                count+=num%2;
                num/=2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};