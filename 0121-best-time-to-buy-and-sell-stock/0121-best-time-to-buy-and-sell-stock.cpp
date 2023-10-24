class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int earn=0;
        
        for(auto i: prices){
            
            mini=min(mini,i);
            maxi=max(maxi,i-mini);
        }
      
        if(maxi<0){
            return 0;
        }
        return maxi;
        
    }
};