import java.io.*;
import java.net.*;
import java.util.Scanner;

public class d32_client {
    public static void main(String args[]){
        int p=9000,i,q=8000;
        String h="localhost";
        try{
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter number of frames : ");
            int number = scanner.nextInt();
            //Socket s2,s1;
            if(number==0){
                System.out.println("No frame is sent");
            }
            else{   
                Socket s2;       
                s2= new Socket(h,q);
                DataOutputStream d1 = new DataOutputStream(s2.getOutputStream());
                d1.write(number);
            }
            //String str1;
            for (i=0;i<number;i++){                 
                System.out.print("Enter message : ");
                String name = scanner.next();
                System.out.println("Frame " + i+" is sent"); 
                Socket s1;
                s1= new Socket(h,p+i);
                DataOutputStream d = new DataOutputStream(s1.getOutputStream());
                d.writeUTF(name);
                DataInputStream dd= new DataInputStream(s1.getInputStream());
                Integer sss1 = dd.read();
                System.out.println("Ack for :" + sss1 + " is  received");
            }
            //s1.close();
            //s2.close();
        }
        catch(Exception ex){
            System.out.println("ERROR :"+ex);
        }
        
    } 
}

