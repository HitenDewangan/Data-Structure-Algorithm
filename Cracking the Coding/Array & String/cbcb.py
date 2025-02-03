def process_zero(matrix, row, col):
    for i in range(row):
        matrix[i][col] = 0
    for j in range(col):
        matrix[row][j] = 0
    
    return


m = int(input())
n = int(input())

matrix = [[int(x) for x in input().split()] for y in range(m)]

row, col = [], []

for i in range(m):
    for j in range(n):
        if(matrix[i][j] == 0):
            row.append(i)
            col.append(j)

process_zero(matrix, row, col)

print(matrix)