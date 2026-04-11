class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        
        unordered_map<char, int> countT, window;
        for(char c:t) countT[c]++;

        int have = 0, need = countT.size();
        pair<int,int> ans = {-1, -1};
        int len = INT_MAX, l=0;

        for(int r=0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c])
                have++;
            
            while(have == need) {
                if((r-l+1) < len) {
                    len = r-l+1;
                    ans = {l,r};
                }

                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
        }
        return INT_MAX == len ? "" : s.substr(ans.first, len);
    }
};
