class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> tokens_stack;
        int result = 0;
        for(string c: tokens) {
            if(c=="+" || c=="*" || c=="-" || c=="/") {
                int num1 = tokens_stack.top();
                tokens_stack.pop();
                int num2 = tokens_stack.top();
                tokens_stack.pop();
                if(c=="+") {
                    tokens_stack.push(num1+num2);
                }
                else if(c=="-") {
                    tokens_stack.push(num2-num1);
                }
                else if(c=="*") {
                    tokens_stack.push(num1*num2);
                }
                else {
                    tokens_stack.push(num2/num1);
                }
            }
            else {
                tokens_stack.push(stoi(c));
            }
        }
        return tokens_stack.top();
    }
};