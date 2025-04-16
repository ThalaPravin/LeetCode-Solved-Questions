class Solution {
public:
    int countHomogenous(string s) {
        int M = 1e9+7, n=s.size() ;
        long long count = 0 ;

        int curr = 1 ;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                curr++; 
            }
            else{
                count+=((long long)curr*(curr+1))/2L;
                curr=1;
            }
        }
        count+=((long long)curr*(curr+1))/2L;
                
        return count%M;
    }
};