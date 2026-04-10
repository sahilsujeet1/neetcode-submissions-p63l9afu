class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, l = 0, maxFreq = 0;
        int arr[26];
        fill(arr, arr+26, 0);

        for(int r=0; r < s.size(); r++) {
            arr[s[r]-'A']++;
            maxFreq = max(maxFreq, arr[s[r]-'A']);

            while ((r-l+1) - maxFreq > k) {
                arr[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
