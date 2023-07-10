arr = [2, 3, 5, 5, 5, 8, 9, 10]
target = 5 
low = 0 
high = len(arr)-1

while low<=high:
    mid = ((low+high)//2)
    if arr[mid]==target:
        result = mid 
        high = mid-1 
    elif arr[mid]<target:
        low = mid+1 
    else:
        high = mid-1 
print(result)


low = 0 
high = len(arr)-1

while low<=high:
    mid = ((low+high)//2)
    if arr[mid]==target:
        result = mid 
        low = mid+1 
    elif arr[mid]<target:
        low = mid+1 
    else:
        high = mid-1 
print(result)