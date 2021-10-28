import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets; 
import java.util.*;

public class ClientUDP {
    public static void process(DatagramSocket ds,Scanner sc){ 
        try{
            System.out.println(""+receive(ds)); 
            String inp = sc.nextLine(); 
            send(inp,ds);
            if(inp.equals("0")){
                System.exit(1); 
            }
            else if(Integer.parseInt(inp)>4){ 
                System.out.println(""+receive(ds)); 
                return;
            }
            System.out.println(receive(ds)); 
            inp = sc.nextLine();
            send(inp,ds);
            inp = sc.nextLine();
            send(inp,ds); System.out.println(""+receive(ds)); 
        }
        catch (IOException e){ 
            System.out.println("IOException " + e);
        }
    }
    public static void send(String msg,DatagramSocket ds) throws IOException {
        byte[] buffer = msg.getBytes(StandardCharsets.UTF_8); 
        DatagramPacket DpSend = new DatagramPacket(buffer, buffer.length, InetAddress.getLocalHost(), 9999); 
        ds.send(DpSend);
    }
    public static String receive(DatagramSocket ds) throws IOException {
        byte[] buf = new byte[2048];
        DatagramPacket DpReceive = new DatagramPacket(buf, buf.length); 
        ds.receive(DpReceive);
        return new
        String(DpReceive.getData(),0,DpReceive.getLength(),StandardCharsets.UTF_8); 
    }
    public static void main(String[] args){
        try{
            DatagramSocket ds = new DatagramSocket(9997);
            Scanner sc = new Scanner(System.in); 
            System.out.print("Calculator server started.....\nWaiting for input....\n");
            while(true){
                process(ds,sc);
            }
        }
        catch (IOException e){
            System.out.println("Something went wrong"); 
        }
    }
}
