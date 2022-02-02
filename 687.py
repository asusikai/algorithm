from idlelib.tree import TreeNode

class Solution:
    longest : int = 0
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        
        def dfs(node: TreeNode):
            if not node:
                return -1
            
            left = 0
            right = 0
            
            if node.val == node.left:
                left = dfs(node.left)
            
            if node.val == node.right:
                right = dfs(node.right)

            self.longest = max(self.longest, left + right +2)

            return max(left, right) + 1

        dfs(root)
        
        return self.longest