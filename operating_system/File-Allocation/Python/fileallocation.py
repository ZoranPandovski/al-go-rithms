
def con():
    # Contigous
    tlist = []

    for i in range(20):
        tlist.append(1)

    tlist[2:7] = [0, 0, 0, 0, 0]
    tlist[9:13] = [0, 0, 0, 0]

    print('Current File: ', tlist)
    n = int(input('Enter no of file: '))

    for i in range(n):
        prev = 0
        s = int(input('enter file {} size: '.format(i+1)))
        c = 0
        for j in range(len(tlist)):
            if tlist[j] == 0:

                c += 1
                if prev == 0:
                    k = j
                    prev = 1
            else:
                c = 0
                prev = 0
            if c == s:
                print('Space is Available, so allocating it')
                for x in range(s):

                    tlist[k] = (i+1)*10
                    k += 1

                print(tlist)
                break

            if j == len(tlist)-1:
                print('No space')

    ch = input('Want to Delete?(y/n)')

    if ch == 'y':
        fnum = int(input('Enter File number to delete: '))

        c = 0

        for j in range(len(tlist)):
            if tlist[j] == fnum*10:
                c += 1
                tlist[j] = 0
        if c == 0:
            print('No such file present')

        else:
            print('File Deleted')
            print('Resultant File: ', tlist)


# Linked List
def ll():

    print('Linked List\n')
    tlist = []

    for i in range(20):
        tlist.append(1)

    tlist[2:4] = [0, 0, 0, 0, 0]
    tlist[9:13] = [0, 0, 0, 0]

    print('Current File: ', tlist)
    n = int(input('Enter no of file: '))

    for i in range(n):
        prev = 0
        s = int(input('enter file {} size: '.format(i+1)))
        st = int(input('Enter Start: '))
        en = int(input('Enter End: '))
        c = 0
        for j in range(st, en):
            if tlist[j] == 0:

                c += 1
                if prev == 0:
                    k = j
                    prev = 1

            if c == s:
                print('Space is Available, so allocating it')
                cc = 0
                for x in range(st, en):

                    if tlist[x] == 0 and cc < s:
                        cc += 1
                        tlist[x] = (i+1)*10

                print(tlist)
                break

            if j == len(tlist)-1:
                print('No space')

    ch = input('Want to Delete?(y/n)')

    if ch == 'y':
        fnum = int(input('Enter File number to delete: '))

        c = 0

        for j in range(len(tlist)):
            if tlist[j] == fnum*10:
                c += 1
                tlist[j] = 0
        if c == 0:
            print('No such file present')

        else:
            print('File Deleted')
            print('Resultant File: ', tlist)

# Indexed
def indexed():

    print('Indexed\n')
    tlist = []

    for i in range(20):
        tlist.append(1)

    tlist[2:4] = [0, 0, 0, 0, 0]
    tlist[9:13] = [0, 0, 0, 0]

    print(tlist)
    n = int(input('Enter no of file: '))

    for i in range(n):
        prev = 0
        s = int(input('enter file {} size: '.format(i+1)))
        ind = int(input('Enter Index: '))

        c = 0

        if tlist[ind] == 0:

            tlist[ind] = (i+1)*100

            for j in range(len(tlist)):
                if tlist[j] == 0:

                    c += 1

                if c == s:
                    print('Space is Available, so allocating it')
                    cc = 0
                    for x in range(len(tlist)):

                        if tlist[x] == 0 and cc < s:
                            cc += 1
                            tlist[x] = (i+1)*10

                    print(tlist)

                    print('Allocation done as follows:\n')

                    for x in range(len(tlist)):
                        if tlist[x] == (i+1)*10:

                            print(ind, '--->', x)

                    break

                # else:
                # print('Noo Space')

                if j == len(tlist)-1:
                    print('No space')
            else:
                print('Index already equipped')

    ch = input('Want to Delete?(y/n)')

    if ch == 'y':
        fnum = int(input('Enter File number to delete: '))

        c = 0

        for j in range(len(tlist)):
            if tlist[j] == fnum*10 or tlist[j] == fnum*100:
                c += 1
                tlist[j] = 0
        if c == 0:
            print('No such file present')

        else:
            print('File and Index Deleted')
            print('Resultant File: ', tlist)

c = 0
while(c <= 3):

    c = int(input('Choose:\n1. Contigous\n2. Linked List\n3. Indexed\n'))

    if c == 1:
        con()

    elif c == 2:
        ll()

    else:
        indexed()

