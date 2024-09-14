class Solution:
    
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = {i: [] for i in range(n)}
            
        for connection in connections:
            adj[connection[0]].append([connection[1], True])
            adj[connection[1]].append([connection[0], False])
        
        def dfs(parent, root):
            # print(adj[root])
            count = 0
            for neighbor, exist in adj[root]:
                if neighbor != parent:
                    if exist:
                        count += 1
                    count += dfs(root, neighbor)
                
            return count
        
        return dfs(-1,0)
        