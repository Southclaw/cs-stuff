/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


class ListenServer extends Thread
{

	protected ServerSocket listenSocket;
	protected int socketPort;

	ListenServer(int port)
	{
		super();
		try
		{
			listenSocket = new ServerSocket(port);
			socketPort = port;
			System.out.format("Created Main ServerSocket on %d\n", port);
		}
		catch(IOException except)
		{
			except.printStackTrace(System.out);
		}
	}

	@Override
	public void run()
	{
		try
		{
			while(true)
			{
				Socket s = listenSocket.accept();
				HandleServer handleServer = new HandleServer(s);
				handleServer.run();
			}
		}
		catch(IOException except)
		{
			except.printStackTrace(System.out);
		}
	}
}
