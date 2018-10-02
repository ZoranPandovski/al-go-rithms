def flatten(myList):
    newList = []
    for item in myList:
        if type(item) == list:
            newList.extend(flatten(item))
        else:
            newList.append(item)
    return newList

def main():
    myList1 = [1,2,3,[1,2],5,[3,4,5,6,7]]
    print(flatten(myList1))
    myList2 = [1,[2,[3,[4,[5,[6,[7,[8,[9]]]]]]]]]
    print(flatten(myList2))

if __name__ == '__main__':
    main()
