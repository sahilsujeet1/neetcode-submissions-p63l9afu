class Solution {
public:
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        return c;
    }

    bool isAlphaNum(char c) {
        return (c >= 'a' && c <='z') || (c >= '0' && c <= '9');
    }

    bool isPalindrome(string str) {
        int s=0, e=str.size()-1;

        while(s < e) {
            if (isAlphaNum(toLower(str[s])) && isAlphaNum(toLower(str[e]))) {
                if(toLower(str[s++]) != toLower(str[e--])) return false;
            } else if (!isAlphaNum(toLower(str[s])) && isAlphaNum(toLower(str[e]))){
                s++;
            }
            else if (isAlphaNum(toLower(str[s])) && !isAlphaNum(toLower(str[e]))){
                e--;
            } else {
                s++; 
                e--;
            }
            
        }
        return true;
    }
};
