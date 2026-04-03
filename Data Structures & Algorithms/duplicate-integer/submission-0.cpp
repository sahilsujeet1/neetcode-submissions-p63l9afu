class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet;

        for(int num:nums)
            numsSet.insert(num);

        return numsSet.size() != nums.size();
    }
};