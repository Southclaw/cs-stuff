/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/
package socialmusicserver;

import java.awt.Frame;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

class HandleServer extends Thread
{
	SocialMusicServer source;
	Socket client;
	OutputStream output;
	InputStream input;
	String stringIn, stringOut;

// **************
	HandleServer(Socket connection, SocialMusicServer s)
	{
		super();
		client = connection;
		source = (SocialMusicServer) s;
		try
		{
			input = client.getInputStream();
			output = client.getOutputStream();
		}
		catch (IOException except)
		{
			except.printStackTrace();
			try
			{
				client.close();
			}
			catch (IOException e)
			{;
			}
			return;
		}
		this.start();
	}

// **************
	public void run()
	{
		String stringIn, stringOut;
		boolean again = true;

		while (again)
		{
			stringIn = getMsg(input);
			System.out.println(stringIn);
		}
	}

// **************
	public String getMsg(InputStream input)
	{
		char[] charArray = new char[1024];
		char c;
		int i = 0;
		try
		{
			while (((c = (char) input.read()) != '#') && (i < 1024))
			{
				charArray[i] = c;
				i++;
			}
		}
		catch (IOException except)
		{
			except.printStackTrace();
		}
		String string = new String(String.valueOf(charArray, 0, i));
		return string;
	}

	public void putMsg(OutputStream output, String string)
	{
		try
		{
			for (int i = 0; i < string.length(); i++)
			{
				output.write((int) string.charAt(i));
			}
		}
		catch (IOException except)
		{
			except.printStackTrace();
		}
	}
}
