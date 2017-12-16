def add(dictionary,key,value):
    dictionary.update({key:value})
    print(dictionary)

def delete(dictionary,key):
    del(dictionary[key])
    print dictionary


dictionary={}
userInput = 'y'
while(userInput=='y' or userInput=='Y'):
    print """ Please enter your choice:
                1. Add to dictionary
                2. Delete a word and meaning
                3. Search
                4. Display entire dictionary
        """
    choice = input("enter your choice")
    if choice==1:
        key = raw_input("Enter the word")
        value = raw_input ("Enter the meaning")
        add(dictionary,key, value)
    elif choice==2:
        key = raw_input("Enter the word")
        delete(dictionary,key, value)
    elif choice==3:
        key = raw_input("Enter the word")
        print dictionary[key]
    elif choice==4:
        for k in sorted(dictionary.keys()):
            print k +": "+ dictionary[k]+"\n"
    else:
        print "wrong choice"
    userInput = raw_input("press y key to repeat and any other key to exit")
print "You have exited the dictionary.. Bye"
