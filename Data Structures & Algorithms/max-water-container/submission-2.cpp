class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int s = 0, e = n-1;
        int currMax = 0;

        while(s < e) {
            int area = (e-s) * min(heights[s], heights[e]);
            currMax = max(currMax, area);
            if (heights[s] > heights[e]) {
                e--;
            } else if (heights[s] < heights[e]) {
                s++;
            } else {
                s++;
                e--;
            }
        }
        return currMax;
    }
};
