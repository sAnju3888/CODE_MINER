def path(matrix,i,j,lookup):
    lookup = {} if lookup is None else lookup 
    n = len(matrix)
    m = len(matrix[0])

    if (i,j) in lookup:
        return lookup[(i,j)]

    if matrix[i][j]==1:
        return 0
    
    if i==n-1 and j==m-1:
        return 1 
    elif i==n-1:
        lookup[(i,j)] = path(matrix,i,j+1,lookup)
        return lookup[(i,j)]
    elif j==m-1:
        lookup[(i,j)] = path(matrix,i+1,j,lookup)
        return lookup[(i,j)]

    else:
        lookup[(i,j)] = path(matrix,i+1,j,lookup) + path(matrix,i,j+1,lookup)
        return lookup[(i,j)]



def main():
    matrix = [[0,0,1,0,1],[0,0,0,0,1],[0,0,1,0,0],[1,0,0,0,0]]
    lookup = {}
    print(path(matrix,0,0,lookup))

if __name__=="__main__":
    main()