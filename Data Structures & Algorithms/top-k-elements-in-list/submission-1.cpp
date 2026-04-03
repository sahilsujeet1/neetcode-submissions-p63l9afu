class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num:nums) count[num]++;

        vector<vector<int>> freq(nums.size() + 1);
        for(auto &entry:count) {
            freq[entry.second].push_back(entry.first);
        }
        vector<int> ans;
        for(int i=freq.size()-1; i>0; i--) {
            for(int num:freq[i]) {
                ans.push_back(num);
                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};
