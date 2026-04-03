class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int num:nums) mp[num]++;
        int ans;

        for(auto pairs:mp) {
            if(pairs.second > n/2) ans = pairs.first;
        }

        return ans;
    }
};