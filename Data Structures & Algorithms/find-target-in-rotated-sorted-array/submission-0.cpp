// class Solution {
// public:
//     int binarySearch(vector<int> &nums, int s, int e, int target) {
//         while(s <= e) {
//             int mid = s + (e-s)/2;
//             if(nums[mid] == target) return mid;
//             else if (nums[mid] < target) s = mid+1;
//             else e = mid-1;
//         }
//         return -1;
//     }

//     int getPivotIndex(vector<int> &nums) {
//         int s = 0, e = nums.size()-1;

//         while(s < e) {
//             int mid = s + (e-s)/2;
//             if (nums[mid] > nums[e]) {
//                 s = e+1;
//             } else {
//                 e = mid;
//             }
//         }
//         return s;
//     }

//     int search(vector<int>& nums, int target) {
//         int s=0, e=nums.size()-1;
//         int pivot = getPivotIndex(nums);

//         int ans = binarySearch(nums, 0, pivot-1, target);
//         if (ans != -1) return ans;

//         return binarySearch(nums, pivot, e, target);
//     }
// };


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;

        int result = binarySearch(nums, target, 0, pivot - 1);
        if (result != -1) {
            return result;
        }

        return binarySearch(nums, target, pivot, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};