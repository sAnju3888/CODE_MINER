def sm(array,start,end):
    sum = 0
    while start<=end:
        sum += array[start] 
        start +=1 
    return sum

def optimum_weight(bagweight,low,high,k):

    

    while low<high:
        start = 0   
        i = 0
        b = []
        mid = ((low+high)//2)
        

        #checking whether i can divide into k group if i take mid as max weight 
        csum = 0
        while i<len(bagweight):
            if csum + bagweight[i]>mid:
                b.append(csum)
                csum = 0
            csum+=bagweight[i]
            i+=1
        b.append(csum)

        print(mid,b)
        if len(b)==k:
            high = mid-1
        elif len(b)!=k:
            low = mid+1
    return high



        
def main():
    # q is choose k trucks should choose continous bags
    # such that max sum of truck is min
    # t1[10,20,30] t2[40,55,60] t3[70,80,85] max sum is 215 but it is not min

    bagweight = [10,20,30,40,55,60,70,80,85]
    no_of_trucks = int(input("ENTER HOW MANY TRUCKS:"))
    #finding a weight optimum by 450 can you divide into k trucks if then reduce the range from l to mid 
    #else mid to high
    low = 0 
    high = sm(bagweight,0,len(bagweight)-1)
    print(optimum_weight(bagweight,low,high,no_of_trucks))


if __name__=="__main__":
    main()