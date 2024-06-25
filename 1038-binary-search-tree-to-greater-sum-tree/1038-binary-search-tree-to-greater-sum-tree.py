# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.total = 0
        
        def reverse_inorder(node): 
            if not node: #Base case to when it reaches the leaf node's child
                return
            
            # Recur on the right subtree
            reverse_inorder(node.right) 
            
            # Update the total and node's value
            self.total += node.val
            node.val = self.total
            
            # Recur on the left subtree
            reverse_inorder(node.left)
        
        reverse_inorder(root)
        return root
