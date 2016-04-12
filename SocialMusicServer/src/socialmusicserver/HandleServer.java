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

	private final Socket socket_;
	private final ListenServer server_;

	public HandleServer(ListenServer server, Socket socket)
	{
		System.out.println("HandleServer constructed");
		this.socket_ = socket;
		this.server_ = server;
	}

	@Override
	public void run()
	{
		System.out.println("Running HandleServer");
		String line;
		BufferedReader input = null;
		PrintWriter output = null;
		int waitForData = 0;

		try
		{
			input = new BufferedReader(new InputStreamReader(socket_.getInputStream()));
			output = new PrintWriter(socket_.getOutputStream(), true);
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
				
				if(line == null)
				{
					// wait 10 seconds for a timeout
					if(waitForData == 10)
					{
						onDisconnect();
						break;
					}

					waitForData++;
					Thread.sleep(100);
					continue;
				}

				String reply = onReceive(line);
				
				if(reply == null)
				{
					System.out.println("Replying with NULL\\n");
					reply = "NULL";
				}

				int size = reply.length();
					
				System.out.printf("Replying with reply: %d '%s'\n", size, reply);
				output.write(size);
				output.print(reply);
				output.print("\n");
				
				output.flush();
			}
			catch(IOException e)
			{
				e.printStackTrace(System.out);
				break;
			}
			catch(InterruptedException e)
			{
				e.printStackTrace(System.out);
				break;
			}
		}
	}
	
	public String onReceive(String s)
	{
		if(s == null)
			return null;

		System.out.printf("onReceive '%s'\n", s);
		String a[] = s.split("\\s+");
		
		System.out.printf("length: %d\n", a.length);
		if(a.length == 0)
		{
			// No commands, quit
			return null;
		}
		
		if(a.length == 1)
		{
			// Handle parameterless commands
			return null;
		}

		return server_.listenEvent(this, a);
	}
	
	private void onDisconnect()
	{
		String[] a = new String[1];
		a[0] = "DSCN";
		server_.listenEvent(this, a);
	}

	protected void finalize()
	{
		try
		{
			onDisconnect();
			this.socket_.close();
		}
		catch(IOException e)
		{
			e.printStackTrace(System.out);
			System.exit(-1);
		}
	}
}
