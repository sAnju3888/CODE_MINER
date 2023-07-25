def longest_sequence(s1,s2,ind1,ind2,lookup=None):
    lookup = {} if lookup is None else lookup

    if ind1 >=len(s1) or ind2 >= len(s2):
        return 0 
    if (ind1,ind2) in lookup:
        return lookup[(ind1,ind2)]
    if s1[ind1]==s2[ind2]:
        lookup[(ind1,ind2)] = 1+longest_sequence(s1,s2,ind1+1,ind2+1)
        return lookup[(ind1,ind2)]
    else:
        #two ways are the eighter ind1 can appear later in ind2 or opposite 
        lookup[(ind1,ind2)] =  max(longest_sequence(s1,s2,ind1+1,ind2),longest_sequence(s1,s2,ind1,ind2+1))
        return lookup[(ind1,ind2)]
    

def main():
    s1 = "abdacbab"
    s2 = "acebfca"
    # in this two strings find length of longest common subsequence 
    # a,b,c,a is present in both strings so length is 4 
    print(longest_sequence(s1,s2,0,0))


if __name__ =="__main__":
    main()
