import java.net.*;
import java.io.*;
import java.nio.charset.StandardCharsets; 
import java.lang.Thread;

public class ServerUDP {
        void run() throws Exception{
            Thread.sleep(6000);
            try {
                DatagramSocket ds = new DatagramSocket(9997);
                String s;
                System.out.println("Socket created. Waiting for incoming data...");
                while (true) {
                    String msg = " Choose: \n 1)Add \n 2)Subtract \n 3)Multiply \n 4)Divide \n 0)Exit:"; 
                    send(msg,ds);
                    int oprnd1, oprnd2;
                    int input = Integer.parseInt(receive(ds)); 
                    switch (input) {
                        case 1 -> {
                            System.out.println("inside case: " + input); 
                            s = "Enter two numbers:";
                            send(s,ds);
                            oprnd1 = Integer.parseInt(receive(ds)); 
                            oprnd2 = Integer.parseInt(receive(ds)); 
                            send("Result= "+(oprnd1 + oprnd2),ds);
                        }
                        case 2 -> {
                            System.out.println("inside case: " + input); 
                            s = "Enter two numbers:";
                            send(s,ds);
                            oprnd1 = Integer.parseInt(receive(ds)); 
                            oprnd2 = Integer.parseInt(receive(ds)); 
                            send("Result="+(oprnd1 - oprnd2),ds);
                        }
                        case 3 -> {
                            System.out.println("inside case: " + input); 
                            s = "Enter two numbers:";
                            send(s,ds);
                            oprnd1 = Integer.parseInt(receive(ds)); 
                            oprnd2 = Integer.parseInt(receive(ds)); 
                            send("Result="+(oprnd1 * oprnd2),ds);
                        }
                        case 4 -> {
                            System.out.println("inside case: " + input); 
                            s = "Enter two numbers:";
                            send(s,ds);
                            oprnd1 = Integer.parseInt(receive(ds)); 
                            oprnd2 = Integer.parseInt(receive(ds));
                            try {
                                send("Result="+(oprnd1 / oprnd2),ds);
                            }
                            catch (ArithmeticException e) {
                                send("Division by 0 not possible",ds); }
                        }
                        case 0 ->
                            send("Server operation closed......",ds);
                        default ->{
                            System.out.println("inside case: " + input); 
                            send("Please enter correct choice",ds);
                        }
                    }
                    if (input == 0){
                        System.out.println("Server closed....!"); ds.close();
                        break;
                    }
                }
            }
            catch(Exception e){
                System.out.println("IOException " + e);
            } 
        }
        public static void send(String msg,DatagramSocket ds) throws IOException {
            byte[] buffer = msg.getBytes(StandardCharsets.UTF_8);
            DatagramPacket DpSend = new DatagramPacket(buffer, buffer.length, InetAddress.getLocalHost(), 9998);
            ds.send(DpSend);
        }
        public static String receive(DatagramSocket ds) throws IOException {
            byte[] buf = new byte[2048];
            DatagramPacket DpReceive = new DatagramPacket(buf, buf.length); 
            ds.receive(DpReceive);
            return new
            String(DpReceive.getData(),0,DpReceive.getLength(),StandardCharsets.UTF_8); 
        }
        public static void main(String[] args) throws Exception { 
            ServerUDP mserver=new ServerUDP(); 
            mserver.run();
        }
}