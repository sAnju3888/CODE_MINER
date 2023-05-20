
from typing import List

class Solution:
    def kthSmallestNum(self, n : int, arr : List[List[int]], q : int, queries : List[int]) -> List[int]:
        # code here
        r = 0
        while r<len(arr)-1:
            if arr[r+1][0] < arr[r][0]:
                arr[r+1],arr[r] = arr[r],arr[r+1]
                r=-1
            if arr[r+1][0]==arr[r][0]:
                if arr[r+1][1] < arr[r][1]:
                    arr[r+1],arr[r] = arr[r],arr[r+1]
                    r=-1
            r+=1
        stack = []
        stack.append(arr[0])
        for i in range(1,len(arr)):
            #non-overlapping
            if (arr[i][0] < stack[-1][0] and arr[i][1] < stack[-1][1]) or arr[i][0]>stack[-1][1]:
                stack.append(arr[i])
            #overlapping
            else:
                if (arr[i][1]>stack[-1][1]):
                    stack[-1][1] = arr[i][1]

        a=[]
        l = 0
        p = []
        
        for i in stack:
            for j in range(i[0],i[1]+1):
                a.append(j)

        for qh in queries:
            if qh>len(a):
                p.append(-1)
            else:
                p.append(a[qh-1])
    
        return p