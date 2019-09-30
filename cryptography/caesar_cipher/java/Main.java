public class Main{
	public static String encrypt(String plain_text){
		String cipher_text = "";
		int shift = 3;
		for(int i=0;i< plain_text.length();i++){
			char ch = (char)(((int)plain_text.charAt(i) + shift - 97) % 26 + 97); 
			cipher_text = cipher_text + ch; 	
		}

		return cipher_text;
	}
	public static void main(String args[]){
		String plain_text = "thestringthatshouldbeencrypted";
		System.out.println(plain_text);
		String cipher_text = encrypt(plain_text);
		System.out.println(cipher_text);
	}
}
