def stockBuySell(price, n):
    if (n == 1):
        return
    i = 0
    while (i < (n - 1)):
        while ((i < (n - 1)) and
               (price[i + 1] <= price[i])):
            i += 1
        if (i == n - 1):
            break
        buy = i
        i += 1
        while ((i < n) and (price[i] >= price[i - 1])):
            i += 1
        sell = i - 1

        print("Buy on day: ", buy, "\t",
              "Sell on day: ", sell)


price = [110, 480, 760, 450, 940, 535, 695]
n = len(price)
stockBuySell(price, n)
