package exp3client;
import java.io.*;
import java.net.Socket;
import java.net.InetAddress;

public class Exp3client {
    
	public static void main(String[] args) 
                throws Exception
	{
    	Socket so=new Socket(InetAddress.getLocalHost(),2500);
    	BufferedReader in=new BufferedReader(new InputStreamReader(so.getInputStream()  ));
    	System.out.println(in.readLine());
	}
}
