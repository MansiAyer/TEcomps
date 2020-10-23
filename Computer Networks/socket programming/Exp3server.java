
package exp3server;
import java.io.*;
import java.util.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Exp3server{
        
        public static void main(String[] args) throws Exception{
    	ServerSocket ss=new ServerSocket(2500);
    	while(true)
    	{
        	System.out.println("Waiting for request from client");
        	Socket so=ss.accept();
        	DataOutputStream out=new DataOutputStream(so.getOutputStream());
        	out.writeBytes("Date and Time of Server: " + (new Date()).toString() + "\n");
        	out.close();
        	so.close();
    	}
	}
}


