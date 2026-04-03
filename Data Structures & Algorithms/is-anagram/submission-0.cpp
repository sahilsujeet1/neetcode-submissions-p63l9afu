class Solution {
public:
    bool isAnagram(string s, string t) {
        int charMap[26];
        for(int i=0; i<26; i++) charMap[i] = 0;

        for(char c:s) charMap[c-'a']++;

        for(char c:t) charMap[c-'a']--;

        for(int i=0; i<26; i++) 
            if(charMap[i] != 0)
                return false;
        
        return true;
    }
};
