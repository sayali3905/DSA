class Solution {
public:
    bool isValid(string s) {
        unordered_map <char, char> brackets;
        stack<char> b_stack;
        int n = s.size();
        brackets['('] = ')';
        brackets['{'] = '}';
        brackets['['] = ']';
        for(char c:s) {
            if(brackets.count(c)) {       //opening bracket
                b_stack.push(c);
            }
            else {                        //closing bracket
                if(b_stack.empty()) {
                    return false;
                }
                else {
                    if(brackets[b_stack.top()]==c) {
                        b_stack.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if(b_stack.empty()) {
            return true;
        }
        else {
            return false;
        }
            
    }
};