class Solution {
public:
    int binarySearch(vector<int> &nums, int s, int e, int target) {
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target) s = mid+1;
            else e = mid-1;
        }
        return -1;
    }

    int getPivotIndex(vector<int> &nums) {
        int s = 0, e = nums.size()-1;

        while(s < e) {
            int mid = s + (e-s)/2;
            if (nums[mid] > nums[e]) {
                s = mid+1;
            } else {
                e = mid;
            }
        }
        return s;
    }

    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        int pivot = getPivotIndex(nums);

        int leftSearch = binarySearch(nums, 0, pivot-1, target);
        if (leftSearch != -1) return leftSearch;

        return binarySearch(nums, pivot, e, target);
    }
};