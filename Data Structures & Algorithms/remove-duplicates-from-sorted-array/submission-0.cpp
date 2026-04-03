#include<bits/stdc++.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //     int n = nums.size();
    //     int k = 0;
    //     for(int i=1; i < n; i++) {
    //         if(nums[i] == nums[i-1]) {
    //             int j = i+1;
    //             while( j < n ) {
    //                 nums[i] = nums[j];
    //             }
    //         }
    //         k++;
    //     }
    //     return k;


        set<int> unique(nums.begin(), nums.end());
        int i = 0;
        for(int num:unique)
            nums[i++] = num;
        return unique.size();
    }
};