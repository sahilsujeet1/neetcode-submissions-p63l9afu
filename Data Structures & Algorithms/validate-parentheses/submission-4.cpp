class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return false;

        stack<char> p;
        for(char c:s) {
            if (c == '(' || c == '{' || c == '[')
                p.push(c);
            else {
                if (
                    !p.empty() &&
                    ((p.top() == '(' && c == ')') ||
                    (p.top() == '{' && c == '}') ||
                    (p.top() == '[' && c == ']'))
                ){
                    p.pop();
                } else {
                    return false;
                }
            }
        }

        return p.empty();

    }
};
