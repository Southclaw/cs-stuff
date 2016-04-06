/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/
package socialmusicserver;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

class HandleServer extends Thread
{

	private final Socket client;

	HandleServer(Socket connection)
	{
		System.out.println("HandleServer constructed");
		this.client = connection;
	}

	@Override
	public void run()
	{
		System.out.println("Running HandleServer");
		String line;
		BufferedReader input = null;
		PrintWriter output = null;

		try
		{
			input = new BufferedReader(new InputStreamReader(client.getInputStream()));
			output = new PrintWriter(client.getOutputStream(), true);
		}
		catch(IOException e)
		{
			e.printStackTrace(System.out);
			return;
		}

		while(true)
		{
			
			try
			{
				System.out.println("Waiting...");
				line = input.readLine();
				System.out.println(line);
				output.println("Reply");
				break;
			}
			catch(IOException e)
			{
				e.printStackTrace(System.out);
			}
		}
	}

	protected void finalize()
	{
		try
		{
			this.client.close();
		}
		catch(IOException e)
		{
			e.printStackTrace(System.out);
			System.exit(-1);
		}
	}
}
