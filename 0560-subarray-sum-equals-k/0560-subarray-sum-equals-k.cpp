class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
        int cnt=0;
        int currsum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            currsum=nums[i];
            if(currsum==goal) cnt++;
            for(int j=i+1; j<n; j++){
                currsum+=nums[j];
                  if(currsum==goal) cnt++;
            }
        }

        return cnt;
    }
};