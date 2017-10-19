
val alphabet = Array("a","b","c","d","e","f","g","h","i","j","k","l","m",
					 "n","o","p","q","r","s","t","u","v","w","x","y","z",
					 "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
					 "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z")

def encrypt(plain_text:String):String={
	//The lenght of the key should be greater than or equal to plain_text
	val key = "welltrytodosopasjkfdssfllo"

	//Inner recursive function to encrypt
	def encrypt_in(ptext:String,ki:Int):String={
		
		if(ptext.isEmpty) "" else
		 alphabet(alphabet.indexOf(ptext.head.toString) + alphabet.indexOf(key(ki).toString)) + encrypt_in(ptext.tail,ki+1)	
	}
	
	encrypt_in(plain_text,0)
		
}


def decrypt(plain_text:String):String={
	
	//The lenght of the key should be greater than or equal to plain_text
	val key = "welltrytodosopasjkfdssfllo"

	//Inner recursive function to decrypt
	def decrypt_in(ptext:String,ki:Int):String={
		
		if(ptext.isEmpty) "" else
		 alphabet(alphabet.indexOf(ptext.head.toString) - alphabet.indexOf(key(ki).toString)) + decrypt_in(ptext.tail,ki+1)	
	}
	
	decrypt_in(plain_text,0)
		
}


def test(){
	val text = "youcantbreakme"
	
	assert(decrypt(encrypt(text)) == text)

}