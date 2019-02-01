class Solution(object):
        def isToeplitzMatrix(self, matrix):
            row = len(matrix)
            col = len(matrix[0])
            i=0;
            for j in range(0,col):
                r = i
                c = j
                num = matrix[r][c]
                while (r<row) and (c<col):
                    if num == matrix[r][c]:
                        r = r+1
                        c = c+1
                        continue
                    else:
                        return 0
            j=0
            for i in range(0,row):
                r = i
                c = j
                num = matrix[r][c]
                while (r<row) and (c<col):
                    if num == matrix[r][c]:
                        r = r+1
                        c = c+1
                        continue
                    else:
                        return 0
            return 1



