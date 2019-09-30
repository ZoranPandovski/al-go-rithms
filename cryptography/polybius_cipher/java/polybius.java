import java.util.Scanner;
public class polybious {

	void cipher(String plainText)

	{

		plainText=plainText.toUpperCase();

		plainText=plainText.replaceAll(" ","");

		plainText=plainText.replaceAll("J","I");



		char allchar[][] = {{'A','B','C','D','E'},{'F','G','H','I','K'},

			{'L','M','N','O','P'}, {'Q','R','S','T','U'},{'V','W','X','Y','Z'}};

		int len=plainText.length();

		char b;

		System.out.println("Cipher Text is Here :");

		for(int i=0; i<len; i++)

		{

			b=plainText.charAt(i);

			for(int j=0; j<5; j++)

			{

				for(int k=0; k<5; k++)

				{

					if(b==allchar[j][k])

					{

						int f=j+1;

						int s=k+1;



						System.out.print(f+" "+s);

						System.out.print("\t");

					}

				}

			}

		}        

	}

}



public class PolybiousSquare {

	public static void main(String[] args) {

		polybious a = new polybious();

		Scanner b = new Scanner(System.in);

		System.out.println("Enter the Plain Text For Cipher ");

		String plainText = b.nextLine();

		a.cipher(plainText);

	}



}
