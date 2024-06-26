# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        # Helper function to perform in-order traversal and collect node values
        def inorderTraversal(node):
            if not node:
                return []
            return inorderTraversal(node.left) + [node.val] + inorderTraversal(node.right)
        
        # Helper function to build a balanced BST from sorted node values
        def buildBalancedBST(nodes, start, end):
            if start > end:
                return None
            mid = (start + end) // 2
            root = TreeNode(nodes[mid])
            root.left = buildBalancedBST(nodes, start, mid - 1)
            root.right = buildBalancedBST(nodes, mid + 1, end)
            return root
        
        # Step 1: Collect sorted node values using in-order traversal
        sorted_nodes = inorderTraversal(root)
        
        # Step 2: Build balanced BST from sorted node values
        return buildBalancedBST(sorted_nodes, 0, len(sorted_nodes) - 1)
