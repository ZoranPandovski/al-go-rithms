
def Print99Bottles(i):
        if (i==99) :
            print("99 bottles of beer on the wall, 99 bottles of beer.")
        elif (i == 0):
            print("Take one down and pass it around, no more bottles of beer on the wall.\n"
                    "No more bottles of beer on the wall, no more bottles of beer.\n"
                    "Go to the store and buy some more, 99 bottles of beer on the wall.")
            return
        else:
            print("Take one down and pass it around, {0} bottles of beer on the wall.\n"
                   "{0} bottles of beer on the wall, {0} bottles of beer.".format(i))

        Print99Bottles(i-1)


Print99Bottles(99)