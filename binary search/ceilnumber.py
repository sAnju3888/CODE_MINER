#program to find ceil number using binary search 

a = [2,3,5,9,14,16,18]
low = 0
high = len(a)-1
target = 15
while low<=high:
    mid = (low+high)//2 
    print(a[mid],a[low],a[high])
    if a[mid]<target:
        low = mid+1
    elif a[mid]>target:
        high = mid-1
    else:
        print(a[mid])
        break
if low>high:
    print(a[low])

