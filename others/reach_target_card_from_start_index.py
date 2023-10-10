"""This is a python program to find the minimum number of left or right moves to reach the target card given start card Index and cards array"""
num_of_cards=int(input("Enter the number of cards: "))#ask user of number of cards
cards=list(map(str,input("Enter cards: ").strip().split(',')))[:num_of_cards]#add the array of cards colors 
startIndex=int(input("Enter starting index: "))#enter the start card index
color=input("Enter target card: ")#enter the color of the target card
endIndex = cards.index(color)#we find the index of target card
#we see different cases that can be made
if(startIndex==endIndex):#if target card and start index are same
    print(0)
elif(abs(startIndex-endIndex)==1):#if target card and start index are adjacent
    print(1)
elif(startIndex<endIndex):#if start index is less than target card index
    forwardDistance=endIndex-startIndex
    backwardDistance=startIndex+(num_of_cards-1-endIndex)+1
    print(min(forwardDistance,backwardDistance))
elif(startIndex>endIndex):#if start index is larger than target card index
    forwardDistance=endIndex+(num_of_cards-1-startIndex)+1
    backwardDistance=startIndex-endIndex
    print(min(forwardDistance,backwardDistance))