def merge(intervals):
    intervals.sort(key = lambda x:x[0])
    new = []       
    top = intervals[0]
    for i in range(1,len(intervals)):
        if intervals[i][0] <= top[1]:
            top[1] = max(intervals[i][1],top[1])
        else:
            new.append(top)
            #print(i,"\n")
            top = intervals[i]
    new.append(top)
    return new