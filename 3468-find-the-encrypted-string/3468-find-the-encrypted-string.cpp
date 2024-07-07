class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n= s.size();
        k=k%n;

        string ans ("");

        for(int i=k; i<n; i++){
            ans.push_back (s[i]);
        }

         for(int i=0; i<k; i++){
            ans.push_back (s[i]);
        }

        return ans;

    }
};