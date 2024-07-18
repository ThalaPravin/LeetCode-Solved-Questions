class Solution {
public:
    void merge(vector<int> & nums, int low, int mid, int high){
        int l=low;
        int r=mid+1;
        vector<int>temp;
        while(l<=mid && r<=high){
            if(nums[l]<= nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
                temp.push_back(nums[r]);
                r++;
            }
        }

        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }

        
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }

        for(int i=low; i<=high; i++){
            nums[i]= temp[i-low];
        }
    }

    void mergeSort(vector<int> & nums, int low, int high){
        if(low>=high )  return;
        int mid= (low+high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};