class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int n:nums) count[n]++;
        vector<int> ans;

        for(auto &entry: count) {
            if(entry.second > nums.size()/3)
                ans.push_back(entry.first);
        }
        return ans;
    }
};