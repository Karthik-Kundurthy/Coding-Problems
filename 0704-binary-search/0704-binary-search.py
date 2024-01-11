class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        def binary_search(low, high, nums, target):
            
            if low > high:
                return -1
        
            # print(nums)
            mid = (low + high)//2
            # print('mid', mid)

            if nums[mid] == target:
                return mid
            
            elif nums[mid] > target:
                return binary_search(low, mid - 1, nums, target)
            
            elif nums[mid] < target:
                return binary_search(mid + 1, high, nums, target)

            else:
                return -1

        n = len(nums) - 1

        return binary_search(0, n, nums, target)
        
        