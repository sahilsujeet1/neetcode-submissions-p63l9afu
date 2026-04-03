class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;

        int i=0, j=numbers.size()-1;

        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                ans = {i+1, j+1};
                break;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};
