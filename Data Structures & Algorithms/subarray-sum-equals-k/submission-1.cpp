class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int ans = 0, currSum = 0;
       unordered_map<int, int> prefixSums;
       prefixSums[0] = 1;

       for(int &num:nums) {
        currSum += num;
        int diff = currSum - k;

        ans += prefixSums[diff];
        prefixSums[currSum]++;
       }

       return ans;
    }
};