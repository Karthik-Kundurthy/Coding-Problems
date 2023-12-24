class MyStack {
private:
    std::queue<int> queue;
public:
    MyStack() {}
    
    // just push
    void push(int x) {
        queue.push(x);
    }
    
    // O(n) to reinsert everything except back element
    int pop() {
        int ret = queue.back();
        int size = queue.size();
        for (int i = 0; i < size - 1; i++) {
            int front = queue.front();
            queue.pop();
            queue.push(front);
        }
        
        queue.pop();
        return ret;
    }
    
    // just get the back
    int top() {
        return queue.back();
    }
    
    // using queue size  
    bool empty() {
        return queue.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */