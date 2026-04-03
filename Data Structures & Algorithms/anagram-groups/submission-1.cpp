class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> aMap;
        vector<vector<string>> ans;

        for(string str:strs) {
            vector<int> freq(26, 0);
            for(char c:str) {
                freq[c-'a']++;
            }
            string key = "";
            for(int i=0; i<26; i++) {
                key += to_string(freq[i]) + ',';
            }
            aMap[key].push_back(str);
        }

        for(auto pairs:aMap) ans.push_back(pairs.second);

        return ans;
    }
};
