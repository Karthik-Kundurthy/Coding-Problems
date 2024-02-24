class MinStack:
    
        
    def __init__(self):
        
        
        self.size = 0
        self.min = float('inf')
        self.stack = []
        
        
    
    def push(self, val: int) -> None:
        if val < self.min:
            self.min = val
        self.stack.append((val, self.min))
        self.size += 1

    def pop(self) -> None:
        
        if self.size == 0:
            return None
        val, _ = self.stack.pop()
        self.size -= 1
        if self.size > 0:
            self.min = self.stack[-1][1]
        else:
            self.min = float('inf')
        return val
        
        

    def top(self) -> int:
        
        if self.size == 0:
            return None
        return self.stack[-1][0]

    def getMin(self) -> int:
        if self.size == 0:
            return None
        return self.stack[-1][1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()