public class Main{
	public static String encrypt(String plain_text){
		
		String cipher_text = "";
		String key = "welltrytodoso";
		int k = 0;
		for(int i=0;i< plain_text.length();i++){
			char ch = (char)(((int)plain_text.charAt(i) + (int)key.charAt(k%key.length())) % 26 + 97); 
			cipher_text = cipher_text + ch; 	
			k=k+1;
		}
		return cipher_text;
	}

	public static String decrypt(String cipher_text){
		
		String plain_text = "";
		String key = "welltrytodoso";
		int k = 0;
		for(int i=0;i< cipher_text.length();i++){	
			char ch;
			int val = (int)cipher_text.charAt(i)-97;
			while( val - (int)key.charAt(k%key.length()) < 97 ){
				val=val+26;
			}
			ch = (char)(val-(int)key.charAt(k%key.length()));
			plain_text = plain_text + ch; 	
			k=k+1;
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
