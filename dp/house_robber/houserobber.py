def robber(i,house,lookup=None):
    lookup={} if  lookup is None else lookup
    if i in lookup:
        return lookup[i]
    if i >= len(house):
        return 0 
    else:
        lookup[i] = max(house[i]+robber(i+2,house),robber(i+1,house))
        return lookup[i]
    
def robber_way2(house):
    dp = [0]*len(house)
    dp[0] = house[0]
    dp[1] = max(dp[0],house[1])
    for i in range(2,len(house)):
        dp[i] = max(dp[i-1],house[i]+dp[i-2])
    print(dp)
    print(dp[-1])

def main():
    house = [50,320,60,40,90]#50+60+90=200
    house = [50,320,60,40,90]#320+40  
    house = [50,320,60,40,90]#320+90 more money i can rob 
    #rule is if you rob at house1 you cant rob adjacent house  
    # rule 2 if you choose housek u can choose housek+2,housen anyhouses 
    i =0 
    print(robber(i,house))
    robber_way2(house)

if __name__=="__main__":
    main()