''' 
Author - Ronak Vadhaiya
Custom hashing and random salt implementation
Sha256 hashing using inbuilt library function and adding random salt implementation for more security
'''


import random
import hashlib


#Custom Hash Function
def hashh(s):
    asc = [str(ord(c)) for c in s]
    asc = int(''.join(asc))

    hexx = hex(asc)
    i = int(hexx,16)
    
    i= i*int(hex(3660),16)
    i= i*int(hex(3421456463465532),16)

    return hex(i)


#Using In-Built Library SHA Hash Function
def encrypt_string(hash_string):
    
    sha_signature = hashlib.sha256(hash_string.encode()).hexdigest()

    return sha_signature


if __name__ == "__main__":

    pwddict = []
    ch=0

    while(ch!=3):
        print("\n\nPassword Storage!! \n 1. Store new password \n 2. Check Password\n 3. Exit")

        ch = int(input("Enter your choice:"))
        if ch==1:
            un = input("Enter username: ")
            pwd = input("Enter Pasword: ")
            salt = "randomsalt" + str(random.randrange(10000, 50000, 1))

            #For own hash
            hashed = hashh(salt + pwd)

            #using library
            hashed = encrypt_string(salt + pwd)

            print(hashed)
            pwddict.append([un,pwd,salt,hashed])
            print(pwddict)

        if ch==2:
            un = input("Enter username: ")
            pwd = input("Enter Password: ")

            for i in pwddict:
                if i[0]==un:
                    salt = i[2]
                    #For own hash
                    hashed = hashh(salt + pwd)

                    #using library
                    hashed = encrypt_string(salt + pwd)

                    if hashed==i[3]:
                        print("Password Correct!!")
                    else:
                        print("Wrong Password!!")

        if ch==3:
            break
