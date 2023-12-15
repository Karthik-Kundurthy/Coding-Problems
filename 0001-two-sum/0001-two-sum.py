class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        vals = {}
        
        for i,num in enumerate(nums):
            if target - num in vals:
                return [i, vals[target -num]]
            else:
                vals[num] = i
                
        return [-1, -1]
        