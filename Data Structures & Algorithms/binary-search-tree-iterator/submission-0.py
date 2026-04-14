# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        self.current = root  # O(1) space — no stack, no pre-processing

    def hasNext(self) -> bool:
        return self.current is not None

    def next(self) -> int:
        while self.current:
            if self.current.left is None:
                val = self.current.val
                self.current = self.current.right   
                return val
            else:
                pred = self.current.left
                while pred.right and pred.right is not self.current:
                    pred = pred.right

                if pred.right is None:
                    pred.right = self.current        
                    self.current = self.current.left
                else:
                    pred.right = None                
                    val = self.current.val
                    self.current = self.current.right
                    return val
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()

