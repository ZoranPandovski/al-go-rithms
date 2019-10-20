def ap(start,difference,terms):
    ans="AP IS : " + str(list(range(start,start+difference*terms,difference)))
    return (ans)

def test():
    return (ap(2,5,10))
test()
    

    
