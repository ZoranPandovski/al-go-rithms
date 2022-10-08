# Coin Change DP using heap
from heapq import heapify, heappush, heappop

def coinChange(self, coins: List[int], amount: int) -> int:
    if not coins:
        return -1
    seen = set()
    heap = [(0,amount)]
    while heap:
        dep,curr = heappop(heap)

        if curr==0:
            return dep
        for coin in coins:
            curramount = curr-coin
            if curramount>=0 and curramount not in seen:
                seen.add(curramount)
                heappush(heap,(dep+1,curramount))

    return -1