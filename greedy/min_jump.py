def jump(a,index):
        if a[index] == 0:
            return float('inf')
        if index == len(a) - 1:
             return 0 
        ab = len(a)
        for new_index in range(index+1,index + a[index]+1):
            if new_index >= len(a):
                break

            else:
                print(a[index],index,a[new_index],new_index)
                #old one for total paths is ab = 0 ab += jump(a,new_index)
                ab  = min(1 + jump(a,new_index),ab)
        # if you want check if path exist if ab == 0 then you cant reach destiny
        return ab
def greedy_jump(a):
     goal = len(a) - 1
     for i in range(len(a)-1,-1,-1):
          if i + a[i] >= goal:
               goal = i 
     return True if goal == 0 else False

def greedy_min_jump(a):
     l = 0 
     r = 0 
     c = 0
     while l < r:
          farthest = 0 
          for i in range(l,r+1):
               farthest = max(farthest,i+a[i])
          l = r + 1
          r = farthest 
     c += 1
     return c + 1
    
def main():
    # this problem is all about can you reach End of the array with jumps 
    #a = [3,2,2,0,4]
    a = [3,2,2,0,4]
    # 3-2-2-1-4
    # 3-2-2-4 
    # 3-1-4 
    # 3-2-1-4
    #  3-2-4
 
    # from index 0 i can go to index1 or index2 or index3 [idont know which leads me to destiny] 
    # from index1 i can go to index2 or index3 [but i dont know which leads me to destiny]
    
    # BRUTE IS  TRY ALL PATHS IF REACHED FINAL INDEX THEN RETURN TRUE 
    i = 0
    print(f"{jump(a,i)} is the minimum length to reach destiny")
    print(f"Can I reach end point? {greedy_jump(a)}")
    print(f"Greedy approach for min jump q?{greedy_min_jump(a)}")


if __name__ == "__main__":
    main()