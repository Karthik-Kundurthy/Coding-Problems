# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    # self.ptr = 0

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        
        # print(root)
        
        
        
        # do preorder traversal, include null nodes
        
        
        ret = ""
        def preorder(curr):
            if curr is None:
                return "N"
            return str(curr.val) + "," + preorder(curr.left) + "," + preorder(curr.right)
            
        
        return preorder(root)
        
        

            
            
        
        
    # decode a postorder traversal with null nodes into a binary tree
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        
        def isLeaf(arr, idx):
            try:
                return arr[idx + 1] == "N" and arr[idx + 2] == "N"
            except Exception as e:
                print(e)
                return False
        
        arr = data.split(",")
        # print(arr)
        
        ptr = 0
        
        def buildTree():
            nonlocal ptr
            if ptr < 0 or ptr >= len(arr):
                return None
            
            if arr[ptr] == "N":
                ptr += 1
                return None
            else:
                root = TreeNode(arr[ptr])
                ptr += 1
                root.left = buildTree()
                root.right = buildTree()
                return root
                
            
        return buildTree()
            
            
            
        
        
        
        
        
        
        # return arr
        
        

                
                

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))





#         # build the nodes
#         nodes = []
#         for ele in arr:
#             if ele != "None":
#                 nodes.append(TreeNode(ele))
#             else:
#                 nodes.append(None)
         
#         print(nodes)
#         for i, ele in enumerate(nodes):
#             if ele is not None:
#                 ele.left = nodes[2*i + 1]
#                 ele.right = nodes[2 * i + 2]
        
#         return nodes[0]
#         queue = []
#         queue.append(root)
        
#         while len(queue) > 0:
#             top = queue.pop()
            
#             if top is not None:
#                 print(top.val)
#                 # print(top.left.val)
#                 queue.append(top.right)
#                 queue.append(top.left)
                
#                 ret += f"{top.val}"
#                 ret += ","
#             else:
#                 ret += "None"
#                 ret += ","
            
#             # ret += ";"
        
#         # print(ret)
        
#         # exclude trailing comma
        # return ret[:-1]