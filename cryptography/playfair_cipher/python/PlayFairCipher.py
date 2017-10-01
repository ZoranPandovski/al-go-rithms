key_matrix = [[0]*5 for i in range(5)] # a global 2-d array to store the key matrix
def generate_matrix(key):
	# This function generates the playfair key matrix used for encryption and decryption process
	matrix = []
	for e in key.upper():
		#For letters in the key
		if e not in matrix:
			matrix.append(e)
	alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
	
	for e in alphabet:
		#for letters which are not in key
		if e not in matrix:
			matrix.append(e)
	key_matrix[0] = matrix[0:5]
	key_matrix[1] = matrix[5:10]
	key_matrix[2] = matrix[10:15]
	key_matrix[3] = matrix[15:20]
	key_matrix[4] = matrix[20:25]
	
def message_to_digraph(original_message):
	# This function converts the message into digraph form

	# Step1 : removing space from the original message
	original_message = original_message.replace(" ","")
	new_message = [] # the list to contain the di-graph
	for char in original_message:
		new_message.append(char)

	#Step 2 : If both letters are same, add an 'X' after the first letter
	i=0
	for i in range(int(len(new_message))-1):
		if new_message[i] == new_message[i+1]:
			new_message.insert(i+1,'X')
			i = i + 2

	#Step 3 : if the length is odd length, then add an 'X'
	if (len(new_message) % 2 == 1):
		new_message.append('X')

	return new_message

def find_position(char):
	# returns the x and y co-ordinate of the passed character in the key matrix
	x , y = 0 , 0
	for i in range(5):
		for j in range(5):
			if key_matrix[i][j] == char:
				x = i
				y = j
				break
	return (x,y)

def playfair(message,key,mode):
	# Produces the cipher or plain text according to the mode
	# if mode == "ENCRYPT" -> encryption
	# if mode == "DECRYPT" -> decryption (don't have to write 2 seperate functions)
	
	message = message_to_digraph(message.upper()) #convert the message into digraph
	print ("THE DI_GRAPH IS : ",end="")
	print (message)
	generate_matrix(key) #generate the key matrix
	print ("THE KEY MATRIX IS AS FOLLOWS : ")
	for i in range(5):
		print (key_matrix[i])
	cipher = []
	i=0
	while(i < int(len(message))):
		char1_x,char1_y = find_position(message[i])
		char2_x,char2_y = find_position(message[i+1])
		if(char1_x == char2_x):
			#both the characters are on same row
			if(mode == "ENCRYPT"):
				#called during encryption
				cipher.append(key_matrix[char1_x][(char1_y+1) % 5])
				cipher.append(key_matrix[char2_x][(char2_y+1) % 5])
			if mode == "DECRYPT":
				#called during decryption
				cipher.append(key_matrix[char1_x][(char1_y-1) % 5])
				cipher.append(key_matrix[char2_x][(char2_y-1) % 5])
		elif(char1_y == char2_y):
			#both the characters are on same column
			if (mode == "ENCRYPT"):
				#used while encryption
				cipher.append(key_matrix[(char1_x+1) % 5][char1_y])
				cipher.append(key_matrix[(char2_x+1) % 5][char2_y])
			if mode == "DECRYPT":
				#used while decryption
				cipher.append(key_matrix[(char1_x-1) % 5][char1_y])
				cipher.append(key_matrix[(char2_x-1) % 5][char2_y])
		else:
			#character are different row and different column
			#this call remains same for both encryption and decryption process
			cipher.append(key_matrix[char1_x][char2_y])
			cipher.append(key_matrix[char2_x][char1_y])
		i = i + 2
	return (cipher) #returns the cipher text in the form of a string
def main():
	print ("------------------PLAYFAIR ENCRYPTION------------------")
	choice = 0
	while (choice != 3):
		choice = int(input("1.Encryption\n2.Decryption\n3.Exit\nEnter an option : "))
		if choice == 1:
			#Encryption
			plain_text = str(input("Enter the plain text : ")).upper()
			key = str(input("Enter the key for encryption : ")).upper()
			print ("Plain Text : ",plain_text)
			print("Cipher Text : ","".join(playfair(plain_text,key,"ENCRYPT")))

		elif choice == 2:
			#Decryption
			cipher_text = str(input("Enter the cipher text : ")).upper()
			key = str(input("Enter the key for decryption : ")).upper()
			print ("Cipher Text : ",cipher_text)
			plain_text = playfair(cipher_text,key,"DECRYPT")
			if 'X' in plain_text:
				plain_text.remove('X')
			print ("".join(plain_text))

		elif choice == 3:
			#Exit
			print ("Bye bye...")
			break

		else:
			print ("Invalid option, Enter an option between (1,3)")
			
if __name__ == '__main__': main()