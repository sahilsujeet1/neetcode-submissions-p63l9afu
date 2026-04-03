class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int num:nums) {
            count[num]++;

            if(count.size() > 2) {
                unordered_map<int, int> newCount;

                for(auto &entry:count) {
                    if(entry.second > 1)
                        newCount[entry.first] = entry.second - 1;
                }
                count = newCount;
            }
        }

        vector<int> ans;
        for(auto &entry:count) {
            int freq = 0;
            for(int num:nums) {
                if(num == entry.first)
                    freq++;
            }
            if(freq > nums.size()/3)
                ans.push_back(entry.first);
        }
        return ans;
    }
};