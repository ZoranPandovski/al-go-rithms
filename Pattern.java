
public class Pattern {

	public static void main(String[] args) 
	{
		//////////////////////***************************////////
		for (int i = 0; i < 5; i++) 
		{
			System.out.println("*");
		}
		///////////////////////////$$$$$$$$$$$$$$$$$$$$/////////////
		for (int j = 0; j < 4; j++) 
		{
			System.out.print("$ ");
		}
		System.out.println();
		for (int j = 0; j <2; j++) 
		{
				System.out.println("$ $");
		}
		for (int j = 0; j < 4; j++) 
		{
			System.out.print("$ ");
		}
		System.out.println();
		////////////////Strings Pattern/////////////
		String s=new String();
		for (int i = 0; i < 5; i++) 
		{
			int a=i+65;
			char c=(char)a;
			System.out.println(s+c);
			s=s+c+" ";
		}
	}

}
