def merge_sort(array):
    if len(array) > 1:
        #lets Begin the Dividing into two subTrees 
        leftarray =  array[:len(array)//2]
        rightarray = array[len(array)//2:]
        merge_sort(leftarray)
        merge_sort(rightarray)
        i = 0 
        j = 0 
        k = 0 
        while i < len(leftarray) and j < len(rightarray):
            if leftarray[i] <= rightarray[j]:
                array[k] = leftarray[i]
                i += 1 
                
            else:
                array[k] = rightarray[j]
                j += 1
                
            k += 1

        while i < len(leftarray):
            array[k] = leftarray[i]
            i += 1
            k += 1
        while j < len(rightarray):
            array[k] = rightarray[j]
            j += 1
            k += 1
    return array

    
def main():
    arr = [1,5,4,3,2,8,7,6]
    print(f"{merge_sort(arr)}")
    

if __name__=="__main__":
    main()