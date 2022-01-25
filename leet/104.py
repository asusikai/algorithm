from collections import deque
from idlelib.tree import TreeNode

def maxDepth(root:TreeNode):
    count = 0
    
    que = deque([root])
    while(que):
        
        for _ in range(len(que)):
            front = que.popleft()
            if front.left:
                que.append(front.left)
            if front.right:
                que.append(front.right)
         
        count += 1
    
    return count