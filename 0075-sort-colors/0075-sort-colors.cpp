class Solution {
public:
    void sortColors(vector<int>& a) {
        int i=0 , j=a.size()-1,k=0;
        
        while(k<=j){
            if(a[k]==2) swap(a[k],a[j--]); 
            
            else if(a[k]==0) swap(a[k++], a[i++]);
            
            else k++;
        }
    }
};