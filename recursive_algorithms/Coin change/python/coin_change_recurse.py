"""
Coin change problem : Given a set of coins (unlimited supply), find number of ways to make change of n 
Example : Given coins (1,2), find number of ways of making change 4
Answer : 3 - [(1,1,1,1) (1,1,2) (2,2)]
"""

def coin_change(change, choices, coin):
    if change == 0:
        return 1
    elif change<0:
        return 0
    else:
        t_ch=0
        for i in range(coin, len(choices)):
            if not choices[i]>change:
                t_ch+=coin_change(change-choices[i], choices, i)
            
        return t_ch

if __name__ == '__main__':
    assert coin_change(5, [1,3,5], 0) == 3
    assert coin_change(7, [1,3,5], 0) == 4