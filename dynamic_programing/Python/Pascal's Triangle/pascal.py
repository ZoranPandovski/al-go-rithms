# Pascal's Triangle
def pascal_triangle(self, numRows: int):
        res = []
        for i in range(0,numRows):
            dem = []
            c = 1
            dem.append(c)
            for j in range(1,i+1):
                if j<=i:
                    c = c * (i-j+1)/j
                    dem.append(int(c))
            # print(dem)
            res.append(dem)
        return(res)

