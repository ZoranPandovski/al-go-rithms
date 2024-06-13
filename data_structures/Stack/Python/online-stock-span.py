class StockSpanner:

    def __init__(self):
        self.a=[]

    def next(self, price: int) -> int:
        c=1
        while self.a and self.a[-1][0]<=price:
            c+=self.a.pop()[1]
        self.a.append((price,c))
        return c
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# param_1 = obj.next(price)