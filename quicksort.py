import numpy as np

def quicksort(arr,lowindex,highindex):
    if lowindex < highindex:

        pivot = highindex
        leftpointer = lowindex
        rightpointer = highindex-1
        while leftpointer <= rightpointer:
            while arr[leftpointer] <= arr[pivot] and leftpointer <= rightpointer:
                leftpointer += 1
            while arr[rightpointer] >= arr[pivot] and leftpointer <= rightpointer:
                rightpointer -= 1
            if leftpointer < rightpointer:
                 arr[leftpointer], arr[rightpointer] = arr[rightpointer], arr[leftpointer]

        arr[pivot],arr[leftpointer] = arr[leftpointer],arr[pivot]
        quicksort(arr,lowindex,leftpointer-1)
        quicksort(arr,leftpointer+1,highindex)
    return arr
    
def main():
    arr = [1,6,3,7,2,9,8,5]
    #print(np.unique(np.array(arr)))
    arr = quicksort(arr,0,len(arr)-1)
    print(arr)

if __name__ == "__main__":
    main()