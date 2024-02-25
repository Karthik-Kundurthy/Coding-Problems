class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        # Have to update every cell as function of the original neighbors
        
        # 0 -> 1, change it to a 2
        # 1 -> 0, change it to a 3
        
        def get_neighbors(game, row, col):
            neighbors = []
            
            directions = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (-1, -1), (-1, 1), (1, -1)]
            
            for direction in directions:
                x, y = direction
                
                i = row + x
                j = col + y
                
                if i >=0 and i < len(game) and j >=0 and j < len(game[0]):
                    neighbors.append(game[i][j])
                
            
            
            mapping = {}
            
            mapping[0] = 0
            mapping[1] = 0
            
            for neighbor in neighbors:
                mapping[neighbor % 2] += 1
                
            return mapping
        
        
        m = len(board)
        n = len(board[0])
        
        for i in range(m):
            for j in range(n):
                cell = board[i][j]
                neighbors = get_neighbors(board, i, j)
                # print(neighbors)
                
                if cell % 2 == 1 and (neighbors[1] < 2 or neighbors[1] > 3):
                    board[i][j] = 3
                elif cell % 2 == 1 and (neighbors[1] == 2 or neighbors[1] == 3):
                    pass
                elif cell % 2 == 0 and neighbors[1] == 3:
                    board[i][j] = 2
        
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 1
                elif board[i][j] == 3:
                    board[i][j] = 0
                    
        return board
                
                
                
                           
                
        