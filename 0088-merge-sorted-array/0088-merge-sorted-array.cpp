class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if (n==0) return;
        // if(m==0) {
        //     nums1=nums2;
        //     return;
        // }

        // for(int i=m; i<m+n; i++){
        //     nums1[i]=nums2[i-m];
        // }
        // sort(nums1.begin(), nums1.end());
        // return;

         int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};