class Solution {
public:
    void mergeSortedArr(vector<int> &nums, int L, int M, int R) {
        vector<int> leftArr, rightArr;
        int idx = L;
        for(int i=0; i<M-L+1; i++)  leftArr.push_back(nums[idx++]);
        idx = M+1;
        for(int i=0; i<R-M; i++)  rightArr.push_back(nums[idx++]);
        
        idx = L;
        int l=0, r=0;
        while(l < leftArr.size() && r < rightArr.size()) {
            if(leftArr[l] < rightArr[r]) nums[idx++] = leftArr[l++];
            else nums[idx++] = rightArr[r++];
        }

        while(l < leftArr.size()) nums[idx++] = leftArr[l++];
        while(r < rightArr.size()) nums[idx++] = rightArr[r++];
    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if(l >= r) return;

        int m = l+(r-l)/2;
        // Left partition sort
        mergeSort(nums, l, m);
        // Right partition sort
        mergeSort(nums, m+1, r);
        // Merge both sorted partitions
        mergeSortedArr(nums, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};