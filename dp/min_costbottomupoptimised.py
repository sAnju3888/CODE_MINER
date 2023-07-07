def min_cost_opt(matrix):
    n = len(matrix)
    m = len(matrix[0])
    dp = [0]*m
    prev_dp = [0]*m 
    prev_dp[0] = matrix[0][0]
    for i in range(1,m):
        prev_dp[i] = matrix[0][i] +  prev_dp[i-1]
    for i in range(1,n):
        dp[0] = matrix[i][0] + prev_dp[0]
        for j in range(1,m):
            dp[j] = matrix[i][j] + min(dp[j-1],prev_dp[j])
        prev_dp = dp 
        dp = [0]*m 
    return prev_dp[m-1]


def main():
    matrix = [[3,2,12,15,10],[6,19,7,11,17],[8,5,12,32,21],[3,20,2,9,7]]
    print(min_cost_opt(matrix))

if __name__=="__main__":
    main()