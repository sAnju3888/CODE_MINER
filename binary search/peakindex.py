def peakIndex(arr):
    low = 0 
    high = len(arr)-1

    while low <= high:
        mid = ((low+high)//2)

        if arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]:
            return arr[mid]
        elif arr[mid]<arr[mid+1]:
            # you are in ascending part of array 
            low = mid+1
        else:
            high = mid-1
    return -1




print(peakIndex([1,2,3,5,6,4,3,2]))