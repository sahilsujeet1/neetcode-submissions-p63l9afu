#define ll long long
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> quad;

    void kSum(vector<int> &nums, int start, ll target, int k) {
        if (k == 2) {
            int l = start, r = nums.size()-1;

            while(l < r) {
                ll sum = (ll) nums[l] + (ll) nums[r];
                if(sum < target) l++;
                else if (sum > target) r--;
                else {
                    quad.push_back(nums[l]);
                    quad.push_back(nums[r]);
                    ans.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    l++;
                    // r--; 
                    while (l < r && nums[l] == nums[l-1]) l++;
                    // while (l < r && nums[r] == nums[r+1]) r--;
                }
            }
            return;
        }

        for(int i=start; i<nums.size()-k+1; i++) {
            if(i > start && nums[i] == nums[i-1]) continue;
            quad.push_back(nums[i]);
            kSum(nums, i+1, target-nums[i], k-1);
            quad.pop_back();
        }

    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());

        kSum(nums, 0, (ll) target, 4);
        return ans;
    }
};