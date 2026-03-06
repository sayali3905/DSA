class MinStack {
private:
    stack<int> main_stack;
    stack<int> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        main_stack.push(val);
        if(minStack.empty()) {
            val = val;
        }
        else {
            val = min(val, minStack.top());
        }
        minStack.push(val);
    }
    
    void pop() {
        main_stack.pop();
        minStack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
