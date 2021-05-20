List = []



boundary = int(input("Enter a boundary value till which you want to carry out the divisibity test : "))

for i in range (1,boundary + 1 ):


 
   
	if (i%7) == 0 and (i%5) == 0:


   
     
		List.append(i) 




print (List)