public class Main{
	public static String encrypt(String plain_text){
		
		String cipher_text = "";
		char[] alphabet =  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		char[] substitutionarray = {'1','4','7','5','F','G','A','B','2','S','N','3','C','T','6','M','6','D','X','R','L','U','K','8','O','9'};

		for(int i=0;i< plain_text.length();i++){
			char ch = substitutionarray[new String(alphabet).indexOf(plain_text.charAt(i))];
			cipher_text = cipher_text + ch; 	
		}
		return cipher_text;
	}

	public static String decrypt(String cipher_text){
		
		String plain_text = "";
		char[] alphabet =  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		char[] substitutionarray = {'1','4','7','5','F','G','A','B','2','S','N','3','C','T','6','M','6','D','X','R','L','U','K','8','O','9'};

		for(int i=0;i< cipher_text.length();i++){
			char ch = alphabet[new String(substitutionarray).indexOf(cipher_text.charAt(i))];
			plain_text = plain_text + ch; 	
		}
		return plain_text;
	}
	public static void main(String args[]){
		String plain_text = "thestringthatshouldbeencrypted";
		System.out.println(plain_text);
		String cipher_text = encrypt(plain_text);
		System.out.println(cipher_text);
		plain_text = decrypt(cipher_text);
		System.out.println(plain_text);
	}
}
