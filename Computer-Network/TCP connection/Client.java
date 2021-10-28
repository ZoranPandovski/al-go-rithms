import java.net.*;
import java.io.*;
import java.util.*;

public class Client {
	public static void process(DataInputStream dis,DataOutputStream dos,Scanner sc){
        try{
			System.out.println(dis.readUTF()); 
			String inp = sc.nextLine(); 
			dos.writeUTF(inp); 
			if(inp.equals("0")){
				System.out.println(""+dis.readUTF()); 
				System.exit(1);
			}
			else if(Integer.parseInt(inp)>4){ 
				System.out.println(""+dis.readUTF());
				return;
			}
			System.out.println(dis.readUTF()); 
			String a = sc.nextLine(); dos.writeUTF(a);
			String b = sc.nextLine(); dos.writeUTF(b); 
			System.out.println(""+dis.readUTF());
    	}
		catch (IOException e){
			System.out.println("IOException " + e);
		}
	}

	public static void main(String[] args) throws Exception {

		//InetAddress ip = InetAddress.getLocalHost();
		Scanner sc = new Scanner(System.in);
		Socket s=new Socket("localhost", 4455);
		DataInputStream dis=new DataInputStream(s.getInputStream()); 
		DataOutputStream dos = new DataOutputStream(s.getOutputStream()); 
		System.out.println(dis.readUTF());
		try{
			while (true){
				process(dis,dos,sc); }
		}
		catch (Exception e){
			System.out.println("Exception:"+e); 
		}
		//return;
	}
}