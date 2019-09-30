import json
import random

def hangman(count):
    hang=[["===============",
          "       |       | ",
          "       O       |  ",
          "     / | \     |   ",
          "      / \      |    ",
          "               |    ",
          "===================="],
          ["===============",
          "       |       | ",
          "       O       |  ",
          "     / | \     |   ",
          "        \      |    ",
          "               |    ",
          "===================="],
          ["===============",
          "       |       | ",
          "       O       |  ",
          "     / | \     |   ",
          "               |    ",
          "               |    ",
          "===================="],
          ["===============",
          "       |       | ",
          "       O       |  ",
          "     / |       |   ",
          "               |    ",
          "               |    ",
          "===================="],
         [ "===============",
          "       |       | ",
          "       O       |  ",
          "       |       |   ",
          "               |    ",
          "               |    ",
          "===================="],
          ["===============",
          "       |       | ",
          "       O       |  ",
          "               |   ",
          "               |    ",
          "               |    ",
          "===================="],
          ["===============",
          "       |       | ",
          "               |  ",
          "               |   ",
          "               |    ",
          "               |    ",
          "===================="],
          ["===============",
          "               | ",
          "               |  ",
          "               |   ",
          "               |    ",
          "               |    ",
          "===================="]
        ]
    for i in hang[count]:
        print(i)
    return

def main():
    with open('animal.json') as f:
        data = json.load(f)
    #print(data)
    
    # animalList=['Tiger','Monkey','Bat','Donkey','Bear']
    name=random.choice(data)
    count = 8
    print('###############################################')
    print('             WELCOME TO HANGMAN                ')
    print('###############################################')
    print('\n\n\n')
    print('Category : Animals')
    l = {}
    
    for i in name:
        l[i]=0
    
    attempt=[]
    char =' '
    flag = False
    status = False
    for i in l:
        if(l[i]==0):
            print('-',end='')
    print('')

    print('Enter character of animal')
    while(count>0 and status == False):
        flag = False
        print('\nEnter character :',end='')
        char = str(input())
        for i in l:
            if(i.lower()==char.lower() and l[i]!=1):
                l[i]=1
                flag = True
        
        if(flag == False):
            attempt.append(char)
            count= count - 1

        for i in l:
            if(l[i]==0):
                print('-',end='')
            else:
                print(i,end='')
        
        print('\nMissed :')
        
        for i in attempt:
            print(i,' ',end='')
        print()
        
        print('Chances remaining :',count)
        status = True
        for i in l:
            if(l[i]==0):
                status = False

        hangman(count)
        
    

    if(status == True):
        print('You won!!!!!!!!!!!!!!!!')
    else:
        print('You ran out of chances !!\nAnimal was :')
        for i in l:
            print(i,end='')
        
    
    print()

        



if __name__ == '__main__':
    main()
