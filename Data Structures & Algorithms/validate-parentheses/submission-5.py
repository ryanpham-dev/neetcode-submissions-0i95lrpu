class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closed = {"}": "{", "]": "[", ")": "("}
        for c in s:
            if c in "{([":
                stack.append(c)
            else:
                if stack and stack.pop() == closed[c]:
                   continue
                else:
                    return False
        return not stack 

        