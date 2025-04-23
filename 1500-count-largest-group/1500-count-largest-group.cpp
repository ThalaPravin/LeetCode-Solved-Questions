class Solution {
public:
    int findDigitSum(int n){
        int sum=0; 
        while(n){
            int temp=n%10;
            n/=10;
            sum+=temp;
        }

        return sum;
    }
    int countLargestGroup(int n) {
        map<int, int>mp;
        int mx=0; 

        for(int i=1; i<=n; i++){
            int temp=findDigitSum(i);

            if(mp.find(temp)!=mp.end()){
                
                mp[temp]++;
            }
            else{
                mp[temp]=1;
            }

            mx= max(mx, mp[temp]);
        }

        int ans=0;

        for(auto i:mp){
            if(i.second == mx){
                ans++;
            }
        }

        return ans;
    }
};