class MinStack:

    def __init__(self):
        self.s = []
        self.prefix = []
        

    def push(self, val: int) -> None:
        self.s.append(val)
        if len(self.prefix) == 0:
            self.prefix.append(val)
        else:
            min_element = val if val < self.prefix[-1] else self.prefix[-1]
            self.prefix.append(val)
            self.prefix.append(min_element)

    def pop(self) -> None:
        self.s.pop()
        self.prefix.pop()
        self.prefix.pop()

    def top(self) -> int:
        return self.s[-1]

    def getMin(self) -> int:
        # return min(self.s) # O(n)
        return self.prefix[-1]


