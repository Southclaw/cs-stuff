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
	
	// send string, get binary
	public byte[] sendb(String message)
	{
		putMsg(output, message);
		return getMsgb(input);
	}

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

			System.out.format("Received size: %d\n", size);
			
			if(size > 2.5e+7)
			{
				System.out.printf("ERROR: Socket data size (%d) out of bounds (%d).\n", size, 2.5e+7);
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

	public byte[] getMsgb(DataInputStream input)
	{
		try
		{
			char c;
			int size = input.readInt();
			int bufferSize=socket.getReceiveBufferSize();
			int readsize = 0;
			byte[] tempArray = new byte[bufferSize];
			byte[] byteArray = new byte[size];
			int byteArrayPtr = 0;

			System.out.format("Expected size: %d Buffer size: %d\n", size, bufferSize);

			if(size > 2.5e+7)
			{
				System.out.printf("ERROR: Socket data size (%d) out of bounds (%d).\n", size, 2.5e+7);
				return null;
			}

			while(byteArrayPtr < size)
			{
				readsize = input.read(tempArray, 0, tempArray.length);

				for(int i = 0; i < readsize && byteArrayPtr < size; i++)
				{
					//System.out.printf("byteArrayPtr : %d/%d readsize: %d i: %d \n", byteArrayPtr, size, readsize, i);
					byteArray[byteArrayPtr] = tempArray[i];
					byteArrayPtr++;
				}
				System.out.printf("byteArrayPtr : %d/%d readsize: %d\n", byteArrayPtr, size, readsize);
			}

			System.out.format("Received size: %d\n", byteArrayPtr);

			return byteArray;
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
