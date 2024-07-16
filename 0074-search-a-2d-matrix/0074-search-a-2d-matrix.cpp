class Solution {
public:

    bool binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true;
        }
        
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    
    return false;
}


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto i: matrix){
            int n=i.size();
            if(i[0]<=target && i[n-1]>=target){
                return binarySearch(i, target);
            }
        }
        return false;
    }
};