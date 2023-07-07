def min_cost_top_down(matrix,i,j,look):
    look = {} if look is None else look
    n = len(matrix)
    m = len(matrix[0]) 
    if (i,j) in look:
        return look[(i,j)]
    if i==n-1 and j==m-1:
        look[(i,j)] = matrix[i][j]
        return look[(i,j)]
    elif i==n-1:
        look[(i,j)] = matrix[i][j]+min_cost_top_down(matrix,i,j+1,look)
        return look[(i,j)]
    elif j==m-1:
        look[(i,j)] = matrix[i][j]+min_cost_top_down(matrix,i+1,j,look)
        return look[(i,j)]     
    else:
        look[(i,j)] = matrix[i][j] + min(min_cost_top_down(matrix,i+1,j,look),min_cost_top_down(matrix,i,j+1,look))
        return look[(i,j)]




def main():
    matrix = [[3,2,12,15,10],[6,19,7,11,17],[8,5,12,32,21],[3,20,2,9,7]]
    look = {}
    print(min_cost_top_down(matrix,0,0,look))





if __name__=="__main__":
    main()