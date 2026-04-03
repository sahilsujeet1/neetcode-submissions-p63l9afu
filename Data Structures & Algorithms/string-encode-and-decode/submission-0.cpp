#include<bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
        if(!strs.size()) return "";

        string encoded = "";
        for(string str:strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        if(!s.size()) return {};

        vector<string> decoded;
        for(int i=0; i<s.size();) {
            int lenIdx = i;
            while(s[lenIdx] != '#') {
                lenIdx++;
            }
            string sizeStr = s.substr(i,lenIdx-i);
            int len = stoi(sizeStr);
            i = lenIdx + 1;
            lenIdx = len + i;
            string str = s.substr(i, len);
            decoded.push_back(str);
            i = lenIdx;
        }

        return decoded;
    }
};
