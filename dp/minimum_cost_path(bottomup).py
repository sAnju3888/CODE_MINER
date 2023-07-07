def minimum_cost_path(matrix):
    n = len(matrix)
    m = len(matrix[0])

    dp = [[0]*m for i in range(n)]
    dp[0][0] = matrix[0][0]
    for row in range(1,m):
        dp[0][row] = matrix[0][row]+dp[0][row-1]

    for column in range(1,n):
        dp[column][0] = matrix[column][0]+dp[column-1][0]
    
    for i in range(1,n):
        for j in range(1,m):
            dp[i][j] = matrix[i][j]+min(dp[i-1][j],dp[i][j-1])        
    return dp[n-1][m-1]


def main():
    matrix = [[3,2,12,15,10],[6,19,7,11,17],[8,5,12,32,21],[3,20,2,9,7]]
    print(minimum_cost_path(matrix))

if __name__=="__main__":
    main()