#define ll long long
int dp[2001][4000];

int find(int pos, int sum, vector<int> &nums)
{
    if(pos == nums.size())
        return 0;
    
    int ans = -1;
    
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
     
    if(nums[pos] > sum) // picking allowed
    {
        ans = max(ans, nums[pos] + find(pos+1, sum+nums[pos], nums)); // picking
        ans = max(ans,  find(pos+1, sum, nums)); // not picking
    }
    
    else
        ans = max(ans, find(pos+1, sum, nums)); // not picking 
    
    return dp[pos][sum] = ans;
}

class Solution {
public:
    int maxTotalReward(vector<int>& rv) {
        
        vector<int> nums;
        unordered_set<int> s;

        memset(dp, -1, sizeof(dp));
        
        for(int i=0; i<rv.size(); ++i)
            s.insert(rv[i]);
        
        for(auto i=s.begin(); i!=s.end(); ++i) // filtering out duplicate elements using sets and sorting the array
            nums.push_back(*i);
        
        sort(nums.begin(), nums.end());
        
        int ans = find(0, 0, nums);
        return ans;
        
    }
};

