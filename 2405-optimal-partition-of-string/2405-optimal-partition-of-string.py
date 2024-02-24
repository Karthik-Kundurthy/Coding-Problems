class Solution:
    def partitionString(self, s: str) -> int:
        count = 0
        
        i = 0
    
        N = len(s)
        
        arr = list(s)
        print(arr)
        
        d = {}
        while i < N:
            while i < N and arr[i] not in d:
                d[arr[i]]= ""
                i += 1

            count += 1
            d = {}   
            

        return count
            
                
            
            
        
        