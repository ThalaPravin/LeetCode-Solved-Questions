class Solution {
    public int numberOfChild(int n, int k) {
        if(k<n) return k;
        int div=k/(n-1);
        if(div%2==0) return k%(n-1) ;
        else return (n-1)-(k%(n-1));
    }
}