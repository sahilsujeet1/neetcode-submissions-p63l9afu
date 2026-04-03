class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> distinctNums(nums.begin(), nums.end());
        int longest = 0;

        for(int num:nums) {
            if(distinctNums.find(num - 1) == distinctNums.end()) {
                int length = 1;
                while(distinctNums.find(num + length) != distinctNums.end())
                    length++;
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
