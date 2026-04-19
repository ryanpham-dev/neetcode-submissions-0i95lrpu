class MinStack:
    
    def __init__(self):
        self.stack = []
        self.min_stack = []
    def push(self, val: int) -> None:
        if len(self.stack) == len(self.min_stack) == 0:
            self.stack.append(val)
            self.min_stack.append(val)
        else:
            current_min = self.min_stack[-1]
            self.stack.append(val)
            if val < current_min:
                self.min_stack.append(val)
            else:
                self.min_stack.append(current_min)

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
