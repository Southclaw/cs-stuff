/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package socialmusicclient;

import java.net.*;
import java.io.*;
import java.util.*;
import java.awt.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Student
 */
public class SocketConnection
{

	Socket socket;
	private OutputStream output;
	private DataInputStream input;

	SocketConnection(String host, int port)
	{
		try
		{
			socket = new Socket(InetAddress.getByName(host), port);
			output = socket.getOutputStream();
			input = new DataInputStream(socket.getInputStream());
		}
		catch(IOException ex)
		{
			Logger.getLogger(SocketConnection.class.getName()).log(Level.SEVERE, null, ex);
		}
	}  // end connectServer 

	public String send(String message)
	{
		putMsg(output, message);
		return getMsg(input);
	}  // end sendReceive  

	public void quitServer()
	{
		try
		{
			socket.close();
		}
		catch(IOException ex)
		{
			Logger.getLogger(SocketConnection.class.getName()).log(Level.SEVERE, null, ex);
		}
	}  // end quitServer

	public String getMsg(DataInputStream input)
	{
		try
		{
			char c;
			int size = input.readInt();
			int i = 0;
			char[] charArray = new char[size];

			System.out.format("Received size: %x\n", size);
			
			if(size > 4096)
			{
				System.out.printf("ERROR: Socket data size (%d) out of bounds.\n", size);
				return null;
			}

			while(i < size)
			{
				c = input.readChar();
				charArray[i] = c;
				i++;
			}
			String string = String.valueOf(charArray);
			return string;
		}
		catch(IOException except)
		{
			except.printStackTrace();
		}  // end catch
		return null;
	}  // end getMsg

// **************
	public void putMsg(OutputStream output, String string)
	{
		try
		{
			for(int i = 0; i < string.length(); i++)
			{
				output.write((int) string.charAt(i));
			}
			if(!string.endsWith("\n"))
			{
				output.write((int) '\n');
			}
		}
		catch(IOException except)
		{
			except.printStackTrace();
		}
	}
}
