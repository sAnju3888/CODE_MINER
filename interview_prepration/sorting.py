def Bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if arr[i] > arr[j]:
                arr[i],arr[j] = arr[j],arr[i]

def optimized_Bubble_sort(arr):
    flagged = True 
    n = len(arr)
    while flagged:
        flagged = False 
        for i in range(1,n):
            if arr[i-1] > arr[i]:
                arr[i],arr[i-1] = arr[i-1],arr[i]
                flagged = True 
        n -= 1
                
def selection_sort(arr):
    for p in range(len(arr)):
        minim = arr[p]
        index = p
        for i in range(p,len(arr)):
            if arr[i] < minim:
                minim = arr[i]
                index = i
        arr[p],arr[index] = arr[index],arr[p]
           
            
def Insertion_sort(arr):
    for i in range(1,len(arr)):
        curr = i
        while curr:
            if arr[curr] < arr[curr-1]:
                arr[curr],arr[curr-1] = arr[curr-1],arr[curr]
            curr -= 1
            
def Merge_sort(arr):
    if len(arr) > 1:
        lsum = arr[0:len(arr)//2]
        rsum = arr[len(arr)//2:len(arr)]
        Merge_sort(lsum)
        Merge_sort(rsum)
        i,j,k = 0,0,0
        
        while i < len(lsum) and j < len(rsum):
            if lsum[i] < rsum[j]:
                arr[k] = lsum[i]
                i += 1
            elif rsum[j] < lsum[i]:
                arr[k] = rsum[j]
                j += 1
            k += 1
        while i < len(lsum):
            arr[k] = lsum[i]
            i += 1
            k += 1
        while j < len(rsum):
            arr[k] = rsum[j]
            j += 1
            k += 1
            
def quick_sort(low,high,arr):
    if (low <= high):
        p = low 
        pivot = high 
        for i in range(low,high):
            if arr[i] < arr[pivot]:
                arr[p],arr[i] = arr[i],arr[p]
                p += 1
        arr[high],arr[p] = arr[p],arr[high]
        quick_sort(low,p-1,arr)
        quick_sort(p+1,high,arr)
        
    
                
def main():
    arr = [5,2,4,1]
    print(f'Array Before Bubblesorting \n{arr}')
    Bubble_sort(arr)
    print(f'Array After Bubblesorting \n{arr}')
    
    arr = [1,2,3,4,5]
    print(f'Array Before  optimized Bubblesorting \n{arr}')
    optimized_Bubble_sort(arr)
    print(f'Array After  optimized Bubblesorting \n{arr}')
    
    
    arr = [5,4,8,3,6]
    print(f'Array Before selection sorting \n{arr}')
    selection_sort(arr)
    print(f'Array After selection sorting \n{arr}')
    
    
    arr = [3,4,6,2]
    print(f'Array Before Insertion sorting \n{arr}')
    Insertion_sort(arr)
    print(f'Array After Insertion Sorting \n{arr}')
    
    
    arr = [3,1,4,2]
    print(f'Array Before Merge Sort \n{arr}')
    Merge_sort(arr)
    print(f'Array After Merge Sort \n{arr}')
    
    arr = [1,5,2,3,6]
    print(f'Array Before Quick Sort \n {arr}')
    quick_sort(0,len(arr)-1,arr)
    print(f'Array After Quick Sort \n {arr}')

if __name__ == "__main__":
    main()