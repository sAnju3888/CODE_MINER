# problem https://www.hackerrank.com/challenges/one-month-preparation-kit-angry-children/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-two

def unfairness(a,b):
    return b - a
def maxMin(k, arr):
    store = float('inf')
    # Write your code here
    arr.sort()
    window_sum = []
    for i in range(len(arr)):
        window_sum.append(arr[i])
        if i >= k-1:
            store =  min(unfairness(window_sum[0],window_sum[-1]),store)
            window_sum.pop(0)
    return store
            
def main():
    # problem statement: given array choose k elements such that (max-min) is minimised
    arr = [1,2,4,7]
    print(maxMin(2,arr))




if __name__ == "__main__":
    main()