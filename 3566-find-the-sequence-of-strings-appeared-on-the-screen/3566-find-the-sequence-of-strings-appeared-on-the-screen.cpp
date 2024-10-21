class Solution {
public:
   vector<string> stringSequence(string t){
    vector<string> v;
    string s="";  
            
    for(char c : t){
        s+='a';
        v.push_back(s);  

        while(s.back()!=c){
            s.back()=(s.back()=='z') ? 'a' : s.back() +1;
            v.push_back(s); 
        }
    }
            
    return v;
}
};