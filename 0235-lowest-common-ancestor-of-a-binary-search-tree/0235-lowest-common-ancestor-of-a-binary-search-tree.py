# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        
        # if p and q are on opposite sides of root, then the root must be the common ancestor
        
        if p.val < root.val and q.val > root.val:
            return root

        
        elif q.val < root.val and p.val > root.val:
            return root
        
        elif p.val == root.val:
            return root
        
        elif q.val == root.val:
            return root
        
        
        elif q.val < root.val and p.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        
        elif p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        
        
        
        return None
            
        
            
            
        
        
        
        # else pass lca to the right or left side