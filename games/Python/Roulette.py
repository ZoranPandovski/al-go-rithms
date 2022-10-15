#roulette-game
import random
import time

print('''Welcome to the ultimate game of Roulette
Play risky! Because no one is your friend here 
Double your money or go home broke!!!''')
a=input('''\nWhat would you like to do?  Choose an option
[Start/End]: ''')
b=random.randrange(0,36,1)
mylist = ["Red", "Black"]
c=random.choice(mylist)
z=1
d=10000
print('''\nThe game goes as follows:-
    -You will be provided a certain amount of money to start with
    -Then you will be placing your desired bet on a Colour or Number
    -If the result is your chosen colour, your bet will double
    -If the result is your chosen number, your will get 20 times the amount of your bet
    -If the number/colour is not of your choice, you will lose the bet amount''')
while d>0:
    if a=='Start':
        e=input('''\nWhat will you be betting on? [Number or Colour]: ''')
        if e=='Number':
            print('''\nYour money(in Rupees):''',d)
            h=int(input('''Enter bet amount: '''))
            f=input('''Choose the number you will be betting on: ''')
            if f==b:
                time.sleep(3)
                print('''\nYour choice was''',f,'''\nThe result was''',b,'''\nCongrats you won!''',h*20)
                d+=h*20
            elif f!=b:
                time.sleep(3)
                print('''\nYour choice was''',f,'''\nThe result was''',b,'''\nSorry, you lost your bet amount''')
                d=d-h
        elif e=='Colour':
            print('''\nYour money(in Rupees):''',d)
            j=int(input('''Enter bet amount: '''))
            k=input('''Choose the colour you will be betting on: ''')
            if k==c:
                time.sleep(3)
                print('''\nYour choice was:-''',k,'''\nThe result was:-''',c,'''\nCongrat you won!''',j*2)
                d+=j*2
            elif k!=c:
                time.sleep(3)
                print('''\nYour choice was:-''',k,'''\nThe result was:-''',c,'''\nSorry, you lost your bet amount''')
                d=d-j
        print('\nYour total amount of the night is: ',d)
    else:
        print('Enter a valid response')
print('\nThank you!')