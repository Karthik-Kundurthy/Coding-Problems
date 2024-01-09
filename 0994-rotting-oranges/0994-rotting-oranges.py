class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        already_appended = set()
        
        queue = []
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    count += 1
                elif grid[i][j] == 2:
                    queue.append((i, j))
                    already_appended.add((i, j))
        
        iterations = 0
        # print(queue, count)
        while count > 0 and len(queue) != 0:
            for k in range(len(queue)):
                # print(queue)
                i, j = queue.pop(0)

                # go left
                if j > 0:
                    left = (i, j - 1)
                    if grid[left[0]][left[1]] == 1:
                        count -= 1
                        grid[left[0]][left[1]] = 2
                        if left not in already_appended:
                            queue.append(left)
                            already_appended.add(left)

                # go right
                if j + 1 < n:
                    right = (i, j + 1)
                    if grid[right[0]][right[1]] == 1:
                        count -= 1
                        grid[right[0]][right[1]] = 2
                        if right not in already_appended:
                            queue.append(right)
                            already_appended.add(right)

                # go down
                if i + 1 < m:
                    down = (i + 1, j)
                    if grid[down[0]][down[1]] == 1:
                        count -= 1
                        grid[down[0]][down[1]] = 2
                        if down not in already_appended:
                            queue.append(down)
                            already_appended.add(down)

                # go up
                if i - 1 >= 0:
                    up = (i - 1, j)
                    if grid[up[0]][up[1]] == 1:
                        count -= 1
                        grid[up[0]][up[1]] = 2
                        if up not in already_appended:
                            queue.append(up)
                            already_appended.add(up)
                        
            iterations += 1
        
        # print("____________________________end___________________________________")
        if count > 0:
            return -1
        else:
            return iterations