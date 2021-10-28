import java.net.*; 
import java.io.*; 
import java.util.*;
   
public class Server { 
	void run() throws Exception {

		try {
			int port = 4455;
			ServerSocket ss = new ServerSocket(port); 
			System.out.println("listening on port =) " + port); 
			Socket s = ss.accept();
			DataInputStream din = new DataInputStream(s.getInputStream()); 
			DataOutputStream dout = new DataOutputStream(s.getOutputStream()); 
			dout.writeUTF("Server waiting for input.....");
			while (true) {
				dout.writeUTF("\n Choose: 1)Add \n 2)Subtract \n 3)Multiply \n 4)Divide \n 0)Exit");
				int oprnd1, oprnd2;
				int input = Integer.parseInt(din.readUTF()); 
				switch (input) {
					case 1 -> {
						System.out.println("inside case: " + input); 
						dout.writeUTF("Enter two numbers:");
						oprnd1 = Integer.parseInt(din.readUTF()); 
						oprnd2 = Integer.parseInt(din.readUTF()); 
						dout.writeUTF("Result:" + (oprnd1 + oprnd2));
					}
					case 2 -> {
						System.out.println("inside case: " + input);
						dout.writeUTF("Enter two numbers:");
						oprnd1 = Integer.parseInt(din.readUTF()); 
						oprnd2 = Integer.parseInt(din.readUTF()); 
						dout.writeUTF("Result:" + (oprnd1 - oprnd2));
					}
					case 3 -> {
						System.out.println("inside case: " + input); 
						dout.writeUTF("Enter two numbers:");
						oprnd1 = Integer.parseInt(din.readUTF()); 
						oprnd2 = Integer.parseInt(din.readUTF()); 
						dout.writeUTF("Result:" + (oprnd1 * oprnd2));
					}
					case 4 -> {
						System.out.println("inside case: " + input); 
						dout.writeUTF("Enter two numbers:");
						oprnd1 = Integer.parseInt(din.readUTF()); 
						oprnd2 = Integer.parseInt(din.readUTF()); 
						try {
							dout.writeUTF("Result=" + (oprnd1 / oprnd2));
						} catch (ArithmeticException e) {
							dout.writeUTF("Result:"+"Division by 0 not possible");
						}
					}
					case 0 ->
						dout.writeUTF("Server operation closed......");
					default -> {
						System.out.println("inside case: default" ); 
						dout.writeUTF("Please choose correct option!\n");
					}
				}
			
				ss.close();
				if (input == 0) {
					ss.close();
					break;
				} 
			}
		}
		catch (Exception e) { 
			System.out.println("Exception:" + e);
		}
	}	
	public static void main(String[] args) throws Exception {
		Server mserver=new Server();
		mserver.run();
	}	
}