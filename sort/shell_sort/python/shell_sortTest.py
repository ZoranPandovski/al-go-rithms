def shellSort (param):
    index = len(param) 
    while index > 0:
        index2 = index
        while index2 < len(param):
            k = param[index2]
            index3 = index2
            while index3 >= index and k < param[index3-index]:
                param[index3] = param[index3-index]
                index3 = index3 - index
            param[index3] = k
            index2 = index2 + 1
        index = int(index/2)
    print(param)
    return param

shellSort([3,9,1,2,5,100,2123,54,34,123,534])
