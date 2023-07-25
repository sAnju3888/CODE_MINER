def birthday(s, d, m):
    # Write your code here
    windowsum = 0 
    windowstart = 0
    c = 0
    for i in range(len(s)):
        windowsum += s[i]
        if i >= m-1:
            print(i)
            if windowsum==d:
                c+=1 
            windowsum -= s[windowstart]
            windowstart+=1
    return c
print(birthday([2,2,1,3,2],4,2))

#https://www.hackerrank.com/challenges/one-month-preparation-kit-the-birthday-bar/problem?h_l=interview&isFullScreen=true&playlist_slugs%5B%5D%5B%5D=preparation-kits&playlist_slugs%5B%5D%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D%5B%5D=one-month-week-one
