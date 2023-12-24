class MyQueue {
private:
    std::stack<int> buffer;
    std::stack<int> queue;
    bool curr;
public:
    // initially using a (curr = true), alternating
    MyQueue() {curr = true;}
    
    // just add to the top of one of the stacks
    void push(int x) {
        buffer.push(x);
    }
    
    // transfer to the other stack, and get the top
    int pop() {
        if (queue.empty()) {
            while (!buffer.empty()) {
                // pop is a void function in C++ stack
                int top = buffer.top();
                buffer.pop();
                queue.push(top);
            }
        }
        int top = queue.top();
        queue.pop();
        return top;
    }
    
    // transfer to other stack and get the top
    int peek() {
        if (queue.empty()) {
            while (!buffer.empty()) {
                int top = buffer.top();
                buffer.pop();
                queue.push(top);
            }
        }
        
        return queue.top();
        
    }
    
    
    // return if curr stack is empty
    bool empty() {
        return buffer.empty() && queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */