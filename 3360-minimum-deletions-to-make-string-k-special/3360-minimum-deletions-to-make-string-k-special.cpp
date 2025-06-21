class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> frq;
        for(auto& ch:word){frq[ch]++;}

        vector<int> v;
        for(auto& val:frq){v.push_back(val.second);}

        sort(begin(v), end(v));

        int n=v.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int range = v[i] + k;

            int tot = v[i];
            for(int j=i+1;j<n;j++){
                if(v[j] > range){ tot += range; }
                else{
                    tot += v[j];
                }
            }

            int remain = word.size() - tot;
            ans = min(ans, remain);
        }

        return ans;
    }
};