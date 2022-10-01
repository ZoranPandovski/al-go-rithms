def gp(start,ratio,terms):
    return ("Required GP is : "+str([start*ratio**n for n in range(0,terms)]))
def test():
    return gp(2,2,10)
    
