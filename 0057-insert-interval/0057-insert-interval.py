class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        intervals.append(newInterval)
        
        intervals.sort(key = lambda x: x[0])
        
        ret = [intervals[0]]
        
        # ret.append(intervals[0])
        
        for i in range(1, len(intervals)):
            curr = intervals[i]
            prev = ret[-1]
            
            if curr[0] <= prev[1]:
                ret[-1][1] = max(ret[-1][1], curr[1])
            else:
                ret.append(curr)
                
        return ret
        