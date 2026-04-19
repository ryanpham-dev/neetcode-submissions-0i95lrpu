class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        output = 0
        stack = []
        for token in tokens:
            match token:
                case "+":
                    while stack:
                        output += int(stack.pop())
                case "-":
                    while stack:
                        output -= stack.pop()
                case "*":
                    while stack:
                        output *= stack.pop()
                case "/":
                    denom = 0
                    while not denom:
                        denom = stack.pop()
                    nom = stack.pop()
                    stack.append(nom // denom)
                case _:
                    stack.append(int(token))
        return output

                
        