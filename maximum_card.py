a = []
def maximum_card(cost,x,i):
    result = []
    if i>=len(cost):
        if sum(a)<=x:
            b = sum([2**cost.index(i) for i in a])
            #print(b)
            result.append(b)
        return result
    a.append(cost[i])
    result.extend(maximum_card(cost,x,i+1))
    a.pop(-1)
    result.extend(maximum_card(cost,x,i+1))
    return result
print(max(maximum_card([10,20,14,40,50],70,0)))


